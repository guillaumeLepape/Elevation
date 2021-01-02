# Clone the repository

This repository contains some libraries and using Github submodules to integrate them. So to clone the repository, the `--recurse-submodule` option has to used. With this option, repository has to be cloned with ssh : 

With SSH :
```shell
    git clone --recurse-submodules git@github.com:guillaumeLepape/Elevation.git
```

# Requirements

1. CMake 3.1 or more
```shell
    sudo apt install cmake 
```
2. Boost 1.71 or more
```shell
    sudo apt install libboost1.71-dev
```

# Compilation

Generate the makefile in repository folder with

```shell
    cmake -Bbuild -S.
```

In repository folder, compile with

```shell
    cmake --build build
```

# Run program

Once the program is compiled, go to `build` folder and run `main` executable by writing
```shell
    ./main
```