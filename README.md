# Clone the repository

This repository contains some libraries and using Github submodules to integrate them. So to clone the repository, the `--recurse-submodule` flag has to used. With this flag, repository has to be cloned with ssh : 

With SSH :
```shell
    git clone --recurse-submodules git@github.com:guillaumeLepape/Elevation.git
```

If you forget to add the flag, running `git submodule update --init` will get all the submodules for you after you’ve cloned.

# Requirements

1. CMake 3.12 or more
```shell
    sudo apt install cmake 
```

# Compilation

Generate the makefile in repository folder with

```shell
    cmake -Bbuild -S.
```

In repository folder, compile with

```shell
    cmake --build <build_folder>
```

To make build faster, you can compile in parallel with the `-j` flag

```shell
    cmake --build <build_folder> -j <nb_core>
```

# Run program

Once the program is compiled, run `main` executable by writing
```shell
    ./<build_folder>/main
```