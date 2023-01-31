use gmt_fem::FEM;
use matio_rs::MatFile;
use nalgebra as na;

#[test]
fn fem_data() -> anyhow::Result<()> {
    let whole_fem = FEM::from_env()?;
    println!("{whole_fem}");

    let matfile = MatFile::load("/home/rconan/projects/m1-ctrl/calib_dt/m1_ctrl_dt.mat")?;

    // Hardpoints stiffness
    println!("HARDPOINTS STIFFNESS");
    let mut fem = whole_fem.clone();
    fem.keep_inputs(&[15]);
    fem.keep_outputs(&[22]);
    let gain = fem.reduced_static_gain().unwrap();
    let mut stiffness = 0f64;
    for i in 0..7 {
        let rows = gain.rows(i * 12, 12);
        let segment = rows.columns(i * 6, 6);
        let cell = segment.rows(0, 6);
        let face = segment.rows(6, 6);
        stiffness += (face - cell).diagonal().map(f64::recip).mean();
    }
    stiffness /= 7f64;
    let m1_hpk: f64 = matfile.var("m1_HPk")?;
    println!("Stiffness: {:.3}/{:.3}", m1_hpk, stiffness);

    // RBM2HP
    println!("RBM 2 HP");
    let mut fem = whole_fem.clone();
    fem.keep_inputs(&[15]);
    fem.keep_outputs(&[24]);
    let gain = fem.reduced_static_gain().unwrap();

    for i in 0..7 {
        println!("S{i}");
        let rbm_2_hp = {
            let rbm_2_hp: Vec<f64> = matfile.var(format!("S{}_M1RBM2HP", i + 1))?;
            na::Matrix6::from_column_slice(rbm_2_hp.as_slice())
        };

        let rows = gain.rows(i * 6, 6);
        let segment = rows
            .columns(i * 6, 6)
            .try_inverse()
            .unwrap()
            .map(|x| x / stiffness);

        println!("Matlab/Rust  : {:.6}{:.6}", rbm_2_hp, segment);
    }

    // LC2CG (include negative feedback)
    println!("LC 2 CG");
    let mut fem = whole_fem.clone();
    fem.keep_inputs(&[16]);
    fem.keep_outputs(&[22]);
    let gain = fem.reduced_static_gain().unwrap();
    // let mut lc_2_cg = na::DMatrix::<f64>::zeros(6, 6);
    for i in 0..7 {
        println!("S{i}");
        let mat_lc_2_cg = {
            let lc_2_cg: na::DMatrix<f64> = if i == 6 {
                matfile.var("CS_LC2CG")
            } else {
                matfile.var("OA_LC2CG")
            }?;
            na::Matrix6::from_column_slice(lc_2_cg.as_slice())
        };

        let rows = gain.rows(i * 12, 12);
        let segment = rows.columns(i * 6, 6);
        let cell = segment.rows(0, 6);
        let face = segment.rows(6, 6);
        let lc_2_cg = (cell - face).try_inverse().unwrap().map(|x| x / stiffness);
        println!("Matlab/Rust  : {:.6}{:.6}", mat_lc_2_cg, lc_2_cg);
    }
    Ok(())
}
