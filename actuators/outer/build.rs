use std::path::PathBuf;

fn main() {
    cc::Build::new()
        .file("sys/M1SA_Control_OA.c")
        .file("sys/M1SA_Control_OA_data.c")
        .compile("m1sa_control_oa");
    println!("cargo:rustc-link-search=native={}", "libm1sa_control_oa");
    println!("cargo:rustc-link-lib=m1sa_control_oa");
    println!("cargo:rerun-if-changed=sys/M1SA_Control_OA.h");

    let bindings = bindgen::builder()
        .header("sys/M1SA_Control_OA.h")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(std::env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
