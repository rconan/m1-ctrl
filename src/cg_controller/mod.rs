use dosio::{
    io::{jar, Tags},
    DOSIOSError, Dos, IOTags, IO,
};
use simulink_rs::*;

import_simulink!(M1OFL_Control, U : (HP_LC,42), Y : (M1_Rel_F,42));
build_inputs!(M1HPLC, 42);
build_outputs!(M1CGFM, 42);
build_controller!(M1OFL_Control,
                  U : (HP_LC -> (M1HPLC,m1_hp_lc)),
                  Y : (M1_Rel_F -> (M1CGFM,m1_cg_fm))
);

impl<'a> IOTags for Controller<'a> {
    fn outputs_tags(&self) -> Vec<Tags> {
        vec![jar::M1CGFM::io()]
    }
    fn inputs_tags(&self) -> Vec<Tags> {
        vec![jar::M1HPLC::io()]
    }
}
impl<'a> Dos for Controller<'a> {
    type Input = Vec<f64>;
    type Output = Vec<f64>;
    fn inputs(&mut self, data: Option<Vec<IO<Self::Input>>>) -> Result<&mut Self, DOSIOSError> {
        match data {
            Some(data) => {
                if data.into_iter().fold(1, |mut a, io| {
                    match io {
                        IO::M1HPLC { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.m1_hp_lc[k] = v;
                            }
                            a -= 1;
                        }
                        _ => (),
                    }
                    if a == 0 {
                        return a;
                    }
                    a
                }) == 0
                {
                    Ok(self)
                } else {
                    Err(DOSIOSError::Inputs(
                        "Either CGcontroller OSSHardpointD or M1HPCmd not found".into(),
                    ))
                }
            }
            None => Err(DOSIOSError::Inputs(
                "None data passed to CG controller".into(),
            )),
        }
    }
    fn outputs(&mut self) -> Option<Vec<IO<Self::Output>>> {
        Some(vec![IO::M1CGFM {
            data: Some(Vec::<f64>::from(&self.m1_cg_fm)),
        }])
    }
}
