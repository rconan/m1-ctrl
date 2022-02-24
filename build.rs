use std::path::Path;

use cc;

fn main() {
    for sid in 1..=7 {
        let c_file = format!("src/actuators/segment{id}/M1SA_F_Control_S{id}.c", id = sid);
        let c_data_file = format!(
            "src/actuators/segment{id}/M1SA_F_Control_S{id}_data.c",
            id = sid
        );
        let lib_file = format!("m1sa_f_control_s{}", sid);
        cc::Build::new()
            .file(c_file)
            .file(c_data_file)
            .compile(&lib_file);
    }
    cc::Build::new()
        .file("src/hp_load_cells/M1_HP_loadcells.c")
        .compile("m1_hp_load_cells");
    let library_path = Path::new("/home/ubuntu/projects/m1-ctrl/src/hp_dynamics");
    cc::Build::new()
        .file("src/hp_dynamics/M1_HP_Dyn.c")
        .include(library_path)
        .compile("m1_hp_dynamics");
    cc::Build::new()
        .file("src/local_controller/M1LocalControl.c")
        .file("src/local_controller/M1LocalControl_data.c")
        .compile("m1_local_controller");
    cc::Build::new()
        .file("src/cg_controller/M1OFL_Control.c")
        .file("src/cg_controller/M1OFL_Control_data.c")
        .compile("m1_cg_controller");
}
