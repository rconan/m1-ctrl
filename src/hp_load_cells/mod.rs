use dosio::{
    io::{jar, Tags},
    DOSIOSError, Dos, IOTags, IO,
};
use simulink_rs::*;

import_simulink!(M1HPloadcells, U : (M1_HP_D,84,M1_HP_cmd,42), Y : (M1_HP_LC,42));
build_inputs!(M1HpD, 84, M1HpCmd, 42);
build_outputs!(M1HpLc, 42);
build_controller!(M1HPloadcells,
                  U : (M1_HP_D -> (M1HpD,m1_hp_d),
                       M1_HP_cmd -> (M1HpCmd,m1_hp_cmd) ),
                  Y : (M1_HP_LC -> (M1HpLc,m1_hp_lc))
);

impl<'a> IOTags for Controller<'a> {
    fn outputs_tags(&self) -> Vec<Tags> {
        vec![jar::M1HPLC::io()]
    }
    fn inputs_tags(&self) -> Vec<Tags> {
        vec![jar::OSSHardpointD::io(), jar::M1HPCmd::io()]
    }
}
impl<'a> Dos for Controller<'a> {
    type Input = Vec<f64>;
    type Output = Vec<f64>;
    fn inputs(&mut self, data: Option<Vec<IO<Self::Input>>>) -> Result<&mut Self, DOSIOSError> {
        match data {
            Some(data) => {
                if data.into_iter().fold(2, |mut a, io| {
                    match io {
                        IO::OSSHardpointD { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.m1_hp_d[k] = v;
                            }
                            a -= 1;
                        }
                        IO::M1HPCmd { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.m1_hp_cmd[k] = v;
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
                        "Either HP load cell controller OSSHardpointD or M1HPCmd not found".into(),
                    ))
                }
            }
            None => Err(DOSIOSError::Inputs(
                "None data passed to HP load cell controller".into(),
            )),
        }
    }
    fn outputs(&mut self) -> Option<Vec<IO<Self::Output>>> {
        Some(vec![IO::M1HPLC {
            data: Some(Vec::<f64>::from(&self.m1_hp_lc)),
        }])
    }
}
