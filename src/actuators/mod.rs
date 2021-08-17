use dosio::{io::Tags, ios, DOSIOSError, Dos, IOTags, IO};
use paste::paste;

pub mod segment1;
pub mod segment2;
pub mod segment3;
pub mod segment4;
pub mod segment5;
pub mod segment6;
pub mod segment7;

macro_rules! impl_dos {
    ($($sid:expr),+) => {
    $(
        paste! {
        impl<'a> IOTags for $crate::actuators::[<segment $sid>]::Controller<'a>   {
            fn outputs_tags(&self) -> Vec<Tags> {
                ios!([<M1S $sid HPLC>], [<M1S $sid BMcmd>])
            }
            fn inputs_tags(&self) -> Vec<Tags> {
                vec![ios!([<M1S $sid ACTF>])]
            }
        }}
        paste! {
        impl<'a> Dos for $crate::actuators::[<segment $sid>]::Controller<'a> {
            type Input = Vec<f64>;
            type Output = Vec<f64>;
            fn inputs(
                &mut self,
                data: Option<Vec<IO<Self::Input>>>,
            ) -> Result<&mut Self, DOSIOSError> {
                if let Some(data) = data {
                    match (&data[ios!([<M1S $sid HPLC>])], &data[ios!([<M1S $sid BMcmd>])]) {
                        (
                            IO::[<M1S $sid HPLC>] { data: Some(hp_lc) },
                            IO::[<M1S $sid BMcmd>] { data: Some(bm_cmd) },
                        ) => {
                            Self::dispatch(&mut self.hp_lc, hp_lc);
                            Self::dispatch(&mut self.bm_cmd, bm_cmd);
                            Ok(self)
                        }
                        _ => Err(DOSIOSError::Inputs(
                            "Missing IO::M1S1HPLC and IO::M1S1BMcmd as inputs to ASM controller"
                                .into(),
                        )),
                    }
                } else {
                    Err(DOSIOSError::Inputs(
                        "Empty inputs passed to ASM controller".into(),
                    ))
                }
            }
            fn outputs(&mut self) -> Option<Vec<IO<Self::Output>>> {
                Some(vec![IO::[<M1S $sid ACTF>] {
                    data: Some(Vec::<f64>::from(&self.m1_act_f)),
                }])
            }
        }})+
    };
}
impl_dos! {1,2,3,4,5,6,7}

/// M1 segment actuators force loop controller
pub enum M1ForceLoopController<'a> {
    One(segment1::Controller<'a>),
    Two(segment2::Controller<'a>),
    Three(segment3::Controller<'a>),
    Four(segment4::Controller<'a>),
    Five(segment5::Controller<'a>),
    Six(segment6::Controller<'a>),
    Seven(segment7::Controller<'a>),
}
impl<'a> IOTags for M1ForceLoopController<'a> {
    fn outputs_tags(&self) -> Vec<Tags> {
        use M1ForceLoopController::*;
        match self {
            One(ctrl) => ctrl.outputs_tags(),
            Two(ctrl) => ctrl.outputs_tags(),
            Three(ctrl) => ctrl.outputs_tags(),
            Four(ctrl) => ctrl.outputs_tags(),
            Five(ctrl) => ctrl.outputs_tags(),
            Six(ctrl) => ctrl.outputs_tags(),
            Seven(ctrl) => ctrl.outputs_tags(),
        }
    }

    fn inputs_tags(&self) -> Vec<Tags> {
        use M1ForceLoopController::*;
        match self {
            One(ctrl) => ctrl.inputs_tags(),
            Two(ctrl) => ctrl.inputs_tags(),
            Three(ctrl) => ctrl.inputs_tags(),
            Four(ctrl) => ctrl.inputs_tags(),
            Five(ctrl) => ctrl.inputs_tags(),
            Six(ctrl) => ctrl.inputs_tags(),
            Seven(ctrl) => ctrl.inputs_tags(),
        }
    }
}
impl<'a> Dos for M1ForceLoopController<'a> {
    type Input = Vec<f64>;
    type Output = Vec<f64>;
    fn outputs(&mut self) -> Option<Vec<IO<Self::Output>>> {
        use M1ForceLoopController::*;
        match self {
            One(ctrl) => ctrl.outputs(),
            Two(ctrl) => ctrl.outputs(),
            Three(ctrl) => ctrl.outputs(),
            Four(ctrl) => ctrl.outputs(),
            Five(ctrl) => ctrl.outputs(),
            Six(ctrl) => ctrl.outputs(),
            Seven(ctrl) => ctrl.outputs(),
        }
    }

    fn inputs(&mut self, data: Option<Vec<IO<Self::Input>>>) -> Result<&mut Self, DOSIOSError> {
        use M1ForceLoopController::*;
        if let Some(data) = data {
            match self {
                One(ctrl) => ctrl
                    .inputs(Some(vec![
                        data[ios!(M1S1HPLC)].clone(),
                        data[ios!(M1S1BMcmd)].clone(),
                    ]))
                    .and(Ok(())),
                Two(ctrl) => ctrl
                    .inputs(Some(vec![
                        data[ios!(M1S2HPLC)].clone(),
                        data[ios!(M1S2BMcmd)].clone(),
                    ]))
                    .and(Ok(())),
                Three(ctrl) => ctrl
                    .inputs(Some(vec![
                        data[ios!(M1S3HPLC)].clone(),
                        data[ios!(M1S3BMcmd)].clone(),
                    ]))
                    .and(Ok(())),
                Four(ctrl) => ctrl
                    .inputs(Some(vec![
                        data[ios!(M1S4HPLC)].clone(),
                        data[ios!(M1S4BMcmd)].clone(),
                    ]))
                    .and(Ok(())),
                Five(ctrl) => ctrl
                    .inputs(Some(vec![
                        data[ios!(M1S5HPLC)].clone(),
                        data[ios!(M1S5BMcmd)].clone(),
                    ]))
                    .and(Ok(())),
                Six(ctrl) => ctrl
                    .inputs(Some(vec![
                        data[ios!(M1S6HPLC)].clone(),
                        data[ios!(M1S6BMcmd)].clone(),
                    ]))
                    .and(Ok(())),
                Seven(ctrl) => ctrl
                    .inputs(Some(vec![
                        data[ios!(M1S7HPLC)].clone(),
                        data[ios!(M1S7BMcmd)].clone(),
                    ]))
                    .and(Ok(())),
            }
        } else {
            Err(DOSIOSError::Inputs(
                "Empty inputs passed to ASMS controllers".into(),
            ))
        }
        .and(Ok(self))
    }
}
/// M1 segment actuators force loops control model
pub struct M1ForceLoops<'a> {
    /// The 7 M1 segments controllers
    pub controllers: Vec<M1ForceLoopController<'a>>,
}
impl<'a> Default for M1ForceLoops<'a> {
    fn default() -> Self {
        use M1ForceLoopController::*;
        Self {
            controllers: vec![
                One(segment1::Controller::new()),
                Two(segment2::Controller::new()),
                Three(segment3::Controller::new()),
                Four(segment4::Controller::new()),
                Five(segment5::Controller::new()),
                Six(segment6::Controller::new()),
                Seven(segment7::Controller::new()),
            ],
        }
    }
}
impl<'a> M1ForceLoops<'a> {
    /// Creates a new M1ForceLoops control model
    pub fn new() -> Self {
        Default::default()
    }
}
impl<'a> Iterator for M1ForceLoops<'a> {
    type Item = ();

    fn next(&mut self) -> Option<Self::Item> {
        use M1ForceLoopController::*;
        self.controllers
            .iter_mut()
            .map(|controller| match controller {
                One(ctrl) => ctrl.step().map(|_| ()),
                Two(ctrl) => ctrl.step().map(|_| ()),
                Three(ctrl) => ctrl.step().map(|_| ()),
                Four(ctrl) => ctrl.step().map(|_| ()),
                Five(ctrl) => ctrl.step().map(|_| ()),
                Six(ctrl) => ctrl.step().map(|_| ()),
                Seven(ctrl) => ctrl.step().map(|_| ()),
            })
            .collect::<Result<Vec<()>, DOSIOSError>>()
            .ok()
            .map(|_| ())
    }
}
impl<'a> Dos for M1ForceLoops<'a> {
    type Input = Vec<f64>;
    type Output = Vec<f64>;

    fn outputs(&mut self) -> Option<Vec<IO<Self::Output>>> {
        use M1ForceLoopController::*;
        self.controllers
            .iter_mut()
            .map(|controller| match controller {
                One(ctrl) => ctrl.outputs().map(|mut x| {
                    vec![ios!(M1ActuatorsSegment1(
                        Option::<Vec<f64>>::from(x.remove(0)).unwrap()
                    ))]
                }),
                Two(ctrl) => ctrl.outputs().map(|mut x| {
                    vec![ios!(M1ActuatorsSegment2(
                        Option::<Vec<f64>>::from(x.remove(0)).unwrap()
                    ))]
                }),
                Three(ctrl) => ctrl.outputs().map(|mut x| {
                    vec![ios!(M1ActuatorsSegment3(
                        Option::<Vec<f64>>::from(x.remove(0)).unwrap()
                    ))]
                }),
                Four(ctrl) => ctrl.outputs().map(|mut x| {
                    vec![ios!(M1ActuatorsSegment4(
                        Option::<Vec<f64>>::from(x.remove(0)).unwrap()
                    ))]
                }),
                Five(ctrl) => ctrl.outputs().map(|mut x| {
                    vec![ios!(M1ActuatorsSegment5(
                        Option::<Vec<f64>>::from(x.remove(0)).unwrap()
                    ))]
                }),
                Six(ctrl) => ctrl.outputs().map(|mut x| {
                    vec![ios!(M1ActuatorsSegment6(
                        Option::<Vec<f64>>::from(x.remove(0)).unwrap()
                    ))]
                }),
                Seven(ctrl) => ctrl.outputs().map(|mut x| {
                    vec![ios!(M1ActuatorsSegment7(
                        Option::<Vec<f64>>::from(x.remove(0)).unwrap()
                    ))]
                }),
            })
            .collect::<Option<Vec<Vec<IO<Vec<f64>>>>>>()
            .map(|x| x.into_iter().flatten().collect())
    }

    fn inputs(&mut self, data: Option<Vec<IO<Self::Input>>>) -> Result<&mut Self, DOSIOSError> {
        use M1ForceLoopController::*;
        if let Some(mut data) = data {
            let mut data_rm = |p: IO<()>| data.remove(data.iter().position(|x| *x == p).unwrap());
            let m1_hp_lc = Option::<Vec<f64>>::from(data_rm(ios!(M1HPLC))).unwrap();
            let mut m1_hp_lc_iter = m1_hp_lc.chunks(6);
            self.controllers
                .iter_mut()
                .map(|controller| match controller {
                    One(ctrl) => ctrl
                        .inputs(Some(vec![
                            ios!(M1S1HPLC(m1_hp_lc_iter.next().unwrap().to_vec())),
                            data_rm(ios!(M1S1BMcmd)),
                        ]))
                        .and(Ok(())),
                    Two(ctrl) => ctrl
                        .inputs(Some(vec![
                            ios!(M1S2HPLC(m1_hp_lc_iter.next().unwrap().to_vec())),
                            data_rm(ios!(M1S2BMcmd)),
                        ]))
                        .and(Ok(())),
                    Three(ctrl) => ctrl
                        .inputs(Some(vec![
                            ios!(M1S3HPLC(m1_hp_lc_iter.next().unwrap().to_vec())),
                            data_rm(ios!(M1S3BMcmd)),
                        ]))
                        .and(Ok(())),
                    Four(ctrl) => ctrl
                        .inputs(Some(vec![
                            ios!(M1S4HPLC(m1_hp_lc_iter.next().unwrap().to_vec())),
                            data_rm(ios!(M1S4BMcmd)),
                        ]))
                        .and(Ok(())),
                    Five(ctrl) => ctrl
                        .inputs(Some(vec![
                            ios!(M1S5HPLC(m1_hp_lc_iter.next().unwrap().to_vec())),
                            data_rm(ios!(M1S5BMcmd)),
                        ]))
                        .and(Ok(())),
                    Six(ctrl) => ctrl
                        .inputs(Some(vec![
                            ios!(M1S6HPLC(m1_hp_lc_iter.next().unwrap().to_vec())),
                            data_rm(ios!(M1S6BMcmd)),
                        ]))
                        .and(Ok(())),
                    Seven(ctrl) => ctrl
                        .inputs(Some(vec![
                            ios!(M1S7HPLC(m1_hp_lc_iter.next().unwrap().to_vec())),
                            data_rm(ios!(M1S7BMcmd)),
                        ]))
                        .and(Ok(())),
                })
                .collect::<Result<Vec<()>, DOSIOSError>>()
                .and(Ok(self))
        } else {
            Err(DOSIOSError::Inputs(
                "Empty inputs passed to ASMS controllers".into(),
            ))
        }
    }
}
