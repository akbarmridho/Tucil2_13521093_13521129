cmake_minimum_required(VERSION 3.25)
project(Tucil2_13521093_13521129)

set(CMAKE_CXX_STANDARD 17)

# include(FetchContent)

# FetchContent_Declare(matplotplusplus
#         GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
#         GIT_TAG origin/master)

# FetchContent_GetProperties(matplotplusplus)
# if(NOT matplotplusplus_POPULATED)
#     FetchContent_Populate(matplotplusplus)
#     add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
# endif()

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
    # src/visualizer.cpp
    # src/visualizer.h
    src/sorter.cpp
    src/sorter.h)

# target_link_libraries(Tucil2_13521093_13521129 PUBLIC matplot)