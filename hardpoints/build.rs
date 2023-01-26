use std::path::PathBuf;

fn main() {
    cc::Build::new()
        .file("sys/HP_dyn_dTF.c")
        .compile("hardpoints_dynamics");
    println!(
        "cargo:rustc-link-search=native={}",
        "libhardpoints_dynamics"
    );
    println!("cargo:rustc-link-lib=hardpoints_dynamics");
    println!("cargo:rerun-if-changed=sys/HP_dyn_dTF.h");

    let bindings = bindgen::builder()
        .header("sys/HP_dyn_dTF.h")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(std::env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
