/*!
# GMT M1 control clients

The module implements the client interface for the GMT M1 control model from the [m1-ctrl] crate,
it includes:
 - the hardpoints dynamics client
 - the hardpoints load cells client
 - the M1 segment actuators force loop client

*The 3 clients are enabled with the `m1-ctrl` feature.*

# Example

M1 hardpoints actor:
```
use dos_actors::clients::m1::*;
use dos_actors::prelude::*;
let mut m1_hardpoints: Actor<_> = m1_ctrl::hp_dynamics::Controller::new().into();
```

M1 load cells actor:
```
# use dos_actors::clients::m1::*;
# use dos_actors::prelude::*;
let sim_sampling_frequency: usize = 1000;//Hz
const M1_RATE: usize = 10;
assert_eq!(sim_sampling_frequency / M1_RATE, 100);
let mut m1_hp_loadcells: Actor<_, 1, M1_RATE> =
    m1_ctrl::hp_load_cells::Controller::new().into();

```

M1 segments actuators actors:
```
# use dos_actors::clients::m1::*;
# use dos_actors::prelude::*;
# let sim_sampling_frequency: usize = 1000;//Hz
# const M1_RATE: usize = 10;
# assert_eq!(sim_sampling_frequency / M1_RATE, 100);
let mut m1_segment1: Actor<_, M1_RATE, 1> =
    super::actuators::segment1::Controller::new().into();
let mut m1_segment2: Actor<_, M1_RATE, 1> =
    super::actuators::segment2::Controller::new().into();
let mut m1_segment3: Actor<_, M1_RATE, 1> =
    super::actuators::segment3::Controller::new().into();
let mut m1_segment4: Actor<_, M1_RATE, 1> =
    super::actuators::segment4::Controller::new().into();
let mut m1_segment5: Actor<_, M1_RATE, 1> =
    super::actuators::segment5::Controller::new().into();
let mut m1_segment6: Actor<_, M1_RATE, 1> =
    super::actuators::segment6::Controller::new().into();
let mut m1_segment7: Actor<_, M1_RATE, 1> =
    super::actuators::segment7::Controller::new().into();
```

[m1-ctrl]: https://docs.rs/m1-ctrl/latest/m1_ctrl/
*/

use super::{hp_dynamics, hp_load_cells};
use dos_actors::{
    impl_read, impl_update, impl_write,
    io::{Data, Read, UniqueIdentifier, Write},
    Update, UID,
};
#[cfg(feature = "fem")]
use fem::fem_io::{OSSHardpointD, OSSHarpointDeltaF};
use std::{ptr, sync::Arc};

#[derive(thiserror::Error, Debug)]
pub enum M1Error {
    #[error("Mode-to-force matrix file not found")]
    Mode2ForceFileNotFound(#[from] std::io::Error),
    #[cfg(feature = "nalgebra")]
    #[error("Mode-to-force deserilization failed")]
    Mode2ForceBin(#[from] bincode::Error),
}
pub type Result<T> = std::result::Result<T, M1Error>;

/// hp_dynamics input
#[derive(UID)]
pub enum M1RBMcmd {}
/// hp_dynamics output
#[derive(UID)]
pub enum HPFcmd {}
/// hp_load_cells input
#[derive(UID)]
pub enum M1HPD {}
/// hp_load_cells input
#[derive(UID)]
pub enum M1HPcmd {}
/// hp_load_cells output
#[derive(UID)]
pub enum M1HPLC {}
/// M1 segment modes
#[derive(UID)]
pub enum M1ModalCmd {}

#[cfg(feature = "nalgebra")]
mod mode2force {
    use super::{Data, M1ModalCmd, Read, Result, UniqueIdentifier, Update, Write};
    use nalgebra as na;
    use std::{env, fs::File, ops::Range, path::Path, sync::Arc};

    /// Convert M1 modes to actuator forces
    pub struct Mode2Force<const S: usize> {
        range: Option<Range<usize>>,
        mode_2_force: na::DMatrix<f64>,
        mode: na::DVector<f64>,
        force: Option<na::DVector<f64>>,
    }
    impl<const S: usize> Mode2Force<S> {
        /// Creates a new mode 2 forces instance for M1 segment #`S`
        ///
        /// The matrices are loaded from [bincode] files given by `path`.
        /// The root directory is given by the environment variable `M1CALIBRATION`
        /// or is the current directory if `M1CALIBRATION` is not set
        pub fn new<P>(n_actuator: usize, n_mode: usize, path: P) -> Result<Self>
        where
            P: AsRef<Path>,
        {
            let root_env = env::var("M1CALIBRATION").unwrap_or_else(|_| ".".to_string());
            let root = Path::new(&root_env);
            let mode_2_force = {
                let mode_2_force: Vec<f64> =
                    bincode::deserialize_from(File::open(root.join(path))?)?;
                na::DMatrix::from_vec(n_actuator, n_mode, mode_2_force)
            };
            Ok(Self {
                range: None,
                mode_2_force,
                mode: na::DVector::zeros(n_mode),
                force: None,
            })
        }
        /// Set the expect # of input modes
        pub fn n_input_mode(self, n: usize) -> Self {
            Self {
                range: Some(n * (S - 1)..n * S),
                ..self
            }
        }
    }
    impl<const S: usize> Update for Mode2Force<S> {
        fn update(&mut self) {
            self.force = Some(&self.mode_2_force * &self.mode);
        }
    }
    impl<U: UniqueIdentifier<Data = Vec<f64>>, const S: usize> Write<U> for Mode2Force<S> {
        fn write(&mut self) -> Option<Arc<Data<U>>> {
            self.force
                .as_ref()
                .map(|force| Arc::new(Data::new(force.as_slice().to_vec())))
        }
    }
    impl<const S: usize> Read<M1ModalCmd> for Mode2Force<S> {
        fn read(&mut self, data: Arc<Data<M1ModalCmd>>) {
            if let Some(range) = &self.range {
                self.mode
                    .iter_mut()
                    .zip(&(**data)[range.to_owned()])
                    .for_each(|(m, d)| *m = *d);
            } else {
                self.mode
                    .iter_mut()
                    .zip(&(**data))
                    .for_each(|(m, d)| *m = *d);
            }
        }
    }
}
#[cfg(feature = "nalgebra")]
pub use mode2force::Mode2Force;

impl_update! {hp_dynamics}
impl_read! {hp_dynamics, (M1RBMcmd, m1_rbm_cmd) }
impl_write! {hp_dynamics, (HPFcmd,  hp_f_cmd)}

impl_update! {hp_load_cells}
impl_read! {hp_load_cells, (M1HPD, m1_hp_d), (M1HPcmd, m1_hp_cmd) }
impl_write! {hp_load_cells, (M1HPLC,  m1_hp_lc)}

#[cfg(feature = "fem")]
impl_write! {OSSHarpointDeltaF, hp_dynamics, (HPFcmd,  hp_f_cmd)}
#[cfg(feature = "fem")]
impl_read! {OSSHarpointDeltaF, hp_load_cells, (M1HPcmd, m1_hp_cmd)}
#[cfg(feature = "fem")]
impl_read! {OSSHardpointD, hp_load_cells, (M1HPD, m1_hp_d)}

use paste::paste;
macro_rules! impl_segments {
    ($($sid:expr),+) => {
        $(
            paste! {
		#[doc = "M1 Segment #$sid hardpoint load cells output"]
		#[derive(UID)]
		pub enum [<S $sid HPLC>] {}
		impl<'a> Write<[<S $sid HPLC>]> for hp_load_cells::Controller<'a> {
		    fn write(&mut self) -> Option<Arc<Data<[<S $sid HPLC>]>>> {
			let hp_load_cells::Y::M1HPLC(val) = &mut self.m1_hp_lc;
			let mut data = vec![0f64; 6];
			let i: usize = 6*($sid - 1);
			unsafe { ptr::copy_nonoverlapping(val[i..].as_ptr(), data.as_mut_ptr(), 6) }
			Some(Arc::new(Data::new(data)))
		    }
		}
		impl<'a> Update for super::actuators::[<segment $sid>]::Controller<'a> {
		    fn update(&mut self) {
			log::debug!("update");
			self.next();
		    }
		}
		impl<'a> Read<[<S $sid HPLC>]> for super::actuators::[<segment $sid>]::Controller<'a> {
		    fn read(&mut self, data: Arc<Data<[<S $sid HPLC>]>>) {
			if let super::actuators::[<segment $sid>]::U::HPLC(val) = &mut self.hp_lc {
			    unsafe { ptr::copy_nonoverlapping((**data).as_ptr(), val.as_mut_ptr(), val.len()) }
			}
		    }
		}
		#[derive(UID)]
		pub enum [<S $sid SAoffsetFcmd>] {}
		impl<'a> Read<[<S $sid SAoffsetFcmd>]> for super::actuators::[<segment $sid>]::Controller<'a> {
		    fn read(&mut self, data: Arc<Data<[<S $sid SAoffsetFcmd>]>>) {
			if let super::actuators::[<segment $sid>]::U::SAoffsetFcmd(val) = &mut self.sa_offsetf_cmd {
			    unsafe { ptr::copy_nonoverlapping((**data).as_ptr(), val.as_mut_ptr(), val.len()) }
			}
		    }
		}
		#[cfg(feature = "fem")]
		use fem::fem_io::[<M1ActuatorsSegment $sid>];
		#[cfg(feature = "fem")]
		impl<'a> Write<[<M1ActuatorsSegment $sid>]> for super::actuators::[<segment $sid>]::Controller<'a> {
		    fn write(&mut self) -> Option<Arc<Data<[<M1ActuatorsSegment $sid>]>>> {
			let super::actuators::[<segment $sid>]::Y::ResActF(val) = &mut self.res_act_f;
			let mut data = vec![0f64; val.len()];
			unsafe { ptr::copy_nonoverlapping(val.as_ptr(), data.as_mut_ptr(), data.len()) }
			Some(Arc::new(Data::new(data)))
		    }
		}
            }
        )+
    };
}
impl_segments! {1,2,3,4,5,6,7}
