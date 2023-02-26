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
    src/sorter.cpp
    src/sorter.h)

# find_package(matplot++ CONFIG REQUIRED)

# if (Matplot++_FOUND)
#     add_executable(Tucil2_13521093_13521129
#             src/main.cpp
#             src/bfsolver.cpp
#             src/bfsolver.h
#             src/datatypes.h
#             src/dncsolver.cpp
#             src/dncsolver.h
#             src/euclidean.cpp
#             src/euclidean.h
#             src/generator.cpp
#             src/generator.h
#             src/visualizer.cpp
#             src/visualizer.h
#             src/sorter.cpp
#             src/sorter.h)
#     target_link_libraries(Tucil2_13521093_13521129 PRIVATE Matplot++::cimg std::filesystem Matplot++::matplot Matplot++::nodesoup)
# endif ()