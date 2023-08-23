# Clone the repository

This repository contains vcpkg to build libraries. So to clone the repository, the `--recurse-submodule` flag is needed. With this flag, repository has to be cloned with ssh :

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

# Vcpkg

To build the libraries, you need to setup vcpkg. To do it, make sure you clone the vcpkg submodule. Run the boostrap script and make the packages available user-side

```shell
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg integrate install
```

# Compilation

Generate the makefile in repository folder with

```shell
cmake -Bbuild -S. -DCMAKE_TOOLCHAIN_FILE=vcpkg/scripts/buildsystems/vcpkg.cmake
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
./<build_folder>/src/main
```

# Test

This program uses googletest to generate tests. By default, tests are compiled. To run them, use the following command

```shell
./build/test/test_elevation
```

# Documentation

## Doxygen

To generate doxygen documentation, go to `doc/Doxygen` folder and run

```
doxygen Doxyfile
```

Open the documentation with

```
firefox html/index.html
```
