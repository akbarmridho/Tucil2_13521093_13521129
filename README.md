# Tucil2_13521093_13521129

## General Information


## Contributors
Created by Group 77:
- 13520093 Akbar Maulana Ridho
- 13520129 Chiquita Ahsanunnisa

## Tech Stack Used
- C++
- Matplot++ Graphics Library
- CMake

## Features
- Solver for closest pair of points in k dimensional space
- Visualization in 3D scatter plot

## Structure

```
|   .gitignore
|   CMakeLists.txt
|   README.md
│ 
├── .vscode
│   └── settings.json
|
├── bin
│   └── execnya apah
│       
├── doc
│   └── Tucil2_13521093_13521129.pdf
│ 
└── src
    |   bfsolver.cpp
    |   bfsolver.h
    |   datatypes.h
    |   dncsolver.cpp
    |   dncsolver.h
    |   euclidean.cpp
    |   euclidean.h
    |   generator.cpp
    |   generator.h
    |   main.cpp
    |   sorter.cpp
    |   sorter.h
    |   visualizer.cpp
    └── visualizer.h
 
    
```

## How to Use

This program was developed on WSL2 Ubuntu 22.04.

### Dependencies
- GNU G++ Compiler
- C++ 17
- CMake 3.25
- Matplot++
- GNUPlot

## How to Install Dependencies

Install GNUPlot

```
sudo apt install gnuplot
```

### How to Compile and Run Program
1. Clone this repo

```
git clone git@github.com:akbarmridho/Tucil2_13521093_13521129.git
```

2. Run cmake build

CMakeList.txt will automatically download Matplot++

```
cmake -B build .
```

3. Run executable file

```
./build/Tucil2_13521093_13521129
```