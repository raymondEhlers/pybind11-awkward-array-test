# BSD 3-Clause License; see https://github.com/jpivarski/awkward-1.0/blob/master/LICENSE

cmake_minimum_required(VERSION 3.15)
project(pybind11_awkward)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#file(READ "VERSION_INFO" VERSION_INFO)
#string(STRIP ${VERSION_INFO} VERSION_INFO)
#add_definitions(-DVERSION_INFO="${VERSION_INFO}")

# Use RPath on Mac OS.
set(CMAKE_MACOSX_RPATH 1)

# Path to additonal modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Resolve warning
#cmake_policy(SET CMP0074 NEW)

# Setup for awkward1
execute_process(COMMAND python -m awkward1.config --incdir OUTPUT_VARIABLE AWKWARD_INCLUDE OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND python -m awkward1.config --libdir OUTPUT_VARIABLE AWKWARD_LIBRARIES OUTPUT_STRIP_TRAILING_WHITESPACE)
include_directories(BEFORE "${AWKWARD_INCLUDE}")
find_library(CPU-KERNELS awkward-cpu-kernels REQUIRED HINTS ${AWKWARD_LIBRARIES})
find_library(LIBAWKWARD awkward REQUIRED HINTS ${AWKWARD_LIBRARIES})

add_subdirectory(pybind11)
pybind11_add_module(_src pybind11_awkward/src/binding.cpp)
target_link_libraries(_src PRIVATE ${CPU-KERNELS} ${LIBAWKWARD})
