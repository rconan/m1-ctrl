//use dosio::{ios, DOSIOSError, Dos, IOTags, IOVec, IO};
mod actors_interface;
pub mod actuators;
pub mod cg_controller;
pub mod hp_dynamics;
pub mod hp_load_cells;
pub mod local_controller;
pub use actors_interface::*;

/*
pub struct MacroController<'a> {
    hardpoints_load_cells: hp_load_cells::Controller<'a>,
    hardpoints_dynamics: hp_dynamics::Controller<'a>,
    actuators_force_loops: actuators::M1ForceLoops<'a>,
}

impl<'a> IOTags for MacroController<'a> {
    fn outputs_tags(&self) -> Vec<IO<()>> {
        let mut tags = self.actuators_force_loops.outputs_tags();
        tags.push(ios!(HPFcmd));
        tags
    }

    fn inputs_tags(&self) -> Vec<IO<()>> {
        ios!(M1RBMcmd, M1S1BMcmd, M1S2BMcmd, M1S3BMcmd, M1S4BMcmd, M1S5BMcmd, M1S6BMcmd, M1S7BMcmd)
    }
}
impl<'a> Iterator for MacroController<'a> {
    type Item = ();

    fn next(&mut self) -> Option<Self::Item> {
        self.hardpoints_load_cells
            .step()
            .ok()
            .and(self.hardpoints_dynamics.step().ok())
            .and(self.actuators_force_loops.step().ok())
            .and(Some(()))
    }
}
impl<'a> Dos for MacroController<'a> {
    type Input = Vec<f64>;
    type Output = Vec<f64>;

    fn outputs(&mut self) -> Option<Vec<IO<Self::Output>>> {
        Some(
            Some(
                self.hardpoints_load_cells
                    .outputs()
                    .into_iter()
                    .chain(self.hardpoints_dynamics.outputs().into_iter())
                    .flatten()
                    .collect::<Vec<IO<Vec<f64>>>>(),
            )
            .into_iter()
            .chain(self.actuators_force_loops.outputs().into_iter())
            .flatten()
            .collect(),
        )
    }

    fn inputs(
        &mut self,
        data: Option<Vec<IO<Self::Input>>>,
    ) -> Result<&mut Self, dosio::DOSIOSError> {
        if let Some(mut data) = data {
            self.hardpoints_load_cells
                .inputs(<Vec<IO<Vec<f64>>> as IOVec>::pop_these(
                    &mut data,
                    ios!(OSSHardpointD, M1HPCmd),
                ))?;
            self.hardpoints_dynamics
                .inputs(<Vec<IO<Vec<f64>>> as IOVec>::pop_these(
                    &mut data,
                    vec![ios!(M1RBMcmd)],
                ))?;
            self.actuators_force_loops.inputs(Some(data))?;
            Ok(self)
        } else {
            Err(DOSIOSError::Inputs(
                "Empty inputs passed to M1 macro controller".into(),
            ))
        }
    }
}
*/
