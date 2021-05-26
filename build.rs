use cc;

fn main() {
    cc::Build::new()
        .file("src/hp_load_cells/M1HPloadcells.c")
        .compile("m1_hp_load_cells");
    cc::Build::new()
        .file("src/local_controller/M1LocalControl.c")
        .file("src/local_controller/M1LocalControl_data.c")
        .compile("m1_local_controller");
    cc::Build::new()
        .file("src/cg_controller/M1OFL_Control.c")
        .file("src/cg_controller/M1OFL_Control_data.c")
        .compile("m1_cg_controller");
}
