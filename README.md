# Clone the repository

This repository contains some libraries and using Github submodules to integrate them. So to clone the repository, the `--recurse-submodule` option has to used. With this option, repository has to with ssh : 

With SSH :
```shell
    git clone --recurse-submodules git@github.com:guillaumeLepape/Elevation.git
```

# Requirements

CMake 3.1 or more
Boost 1.71 or more

# Compilation

Create the `build` directory in this folder and go to it with

```shell
    mkdir build
    cd build
```

Generate the makefile in `build` folder with

```shell
    cmake ..
```

In `build` folder, compile with

```shell
    make
```