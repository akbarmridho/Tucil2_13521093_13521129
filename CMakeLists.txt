cmake_minimum_required(VERSION 3.25)
project(Tucil2_13521093_13521129)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tucil2_13521093_13521129
    src/main.cpp
    src/bfsolver.cpp
    src/bfsolver.h
    src/datatypes.h
    src/dncsolver.cpp
    src/dncsolver.h
    src/euclidean.cpp
    src/euclidean.h
    src/generator.cpp
    src/generator.h
    src/io.cpp
    src/io.h
    src/sorter.cpp
    src/sorter.h)

set_target_properties(Tucil2_13521093_13521129
    PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR}/../bin)