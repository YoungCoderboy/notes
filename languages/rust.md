# Introduction

- `rustup` is command line tool for managing rust version and associated tools
- `.rs` is ending extension for rust program

```rust
fn main() {
    println!("Hello, world!");
}
```

- `rustc main.rc` then `./main.rc` to run this file
- The main function is special: it is always the first code that runs in every executable Rust program.
- println! calls a Rust macro. If it had called a function instead, it would be entered as println (without the !).
- Rust is an ahead-of-time compiled language, meaning you can compile a program and give the executable to someone else, and they can run it even without having Rust installed.

### Rust Cargo

- Cargo is Rust’s build system and package manager. Most Rustaceans use this tool to manage their Rust projects because Cargo handles a lot of tasks for you, such as building your code, downloading the libraries your code depends on, and building those libraries. (We call the libraries that your code needs dependencies.)

```cmd
$ cargo new hello_cargo
$ cd hello_cargo
<!-- Go into the hello_cargo directory and list the files. You’ll see that Cargo has generated two files and one directory for us: a Cargo.toml file and a src directory with a main.rs file inside. -->
```

```toml
[package]
name = "hello_cargo"
version = "0.1.0"
edition = "2024"

[dependencies]
```

- [dependencies], is the start of a section for you to list any of your project’s dependencies. In Rust, packages of code are referred to as crates.
- One easy way to get that Cargo.toml file is to run cargo init, which will create it for you automatically.

```cmd
$ cargo build
   Compiling hello_cargo v0.1.0 (file:///projects/hello_cargo)
    Finished dev [unoptimized + debuginfo] target(s) in 2.85 secs

```

- This command creates an executable file in target/debug/hello_cargo (or target\debug\hello_cargo.exe on Windows) rather than in your current directory. Because the default build is a debug build, Cargo puts the binary in a directory named debug.

```cmd
$ ./target/debug/hello_cargo # or .\target\debug\hello_cargo.exe on Windows
Hello, world!
```

- Running cargo build for the first time also causes Cargo to create a new file at the top level: Cargo.lock. This file keeps track of the exact versions of dependencies in your project. This project doesn’t have dependencies, so the file is a bit sparse. You won’t ever need to change this file manually; Cargo manages its contents for you.

- We just built a project with cargo build and ran it with ./target/debug/hello_cargo, but we can also use cargo run to compile the code and then run the resultant executable all in one command

- Cargo figured out that the files hadn’t changed, so it didn’t rebuild but just ran the binary. If you had modified your source code, Cargo would have rebuilt the project before running it

- Cargo also provides a command called cargo check. This command quickly checks your code to make sure it compiles but doesn’t produce an executable

- When your project is finally ready for release, you can use cargo build --release to compile it with optimizations. This command will create an executable in target/release instead of target/debug. The optimizations make your Rust code run faster, but turning them on lengthens the time it takes for your program to compile. This is why there are two different profiles: one for development, when you want to rebuild quickly and often, and another for building the final program you’ll give to a user that won’t be rebuilt repeatedly and that will run as fast as possible. If you’re benchmarking your code’s running time, be sure to run cargo build --release and benchmark with the executable in target/release.
