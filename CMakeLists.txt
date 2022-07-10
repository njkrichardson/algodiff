cmake_minimum_required(VERSION 3.0) 
project(algodiff)

# --- search the directory tree 
file(GLOB_RECURSE sources src/*.cpp include/*.h)

# --- target compilation flags 
target_compile_options(example PUBLIC -std=c++17 -Wall -Wfloat-conversion)

# --- install the package 
set(CPACK_PACKAGE_NAME "Algodiff")
set(CPACK_PACKAGE_VERSION "0.0.1")

set(CPACK_MONOLITHIC_INSTALL 1)

include(CPack)
