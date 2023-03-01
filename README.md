# Tucil2_13521093_13521129

## General Information
A program to solve closest pair of points problem in multidimensional space using divide and conquer algorithm design. Program will show the coordinates of the closest pair of points and visualize the result in 3D scatter plot (only if it's in three dimensional space).

## Contributors
Created by Group 77:
- 13520093 Akbar Maulana Ridho
- 13520129 Chiquita Ahsanunnisa

## Programming Language Used
- C++
- Python

## Features
- Solver for closest pair of points in k dimensional space (in C++)
- Visualization in 3D scatter plot (in Python)

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
│   └── Tucil2_13521093_13521129
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
    |   io.cpp
    |   io.h
    |   generator.cpp
    |   generator.h
    |   main.cpp
    |   sorter.cpp
    |   sorter.h
    └── visualizer.py
    
```

## How to Use

This program was developed on WSL2 Ubuntu 22.04.

### Dependencies
- GNU G++ Compiler
- C++ 17
- CMake 3.25
- Python 3
- Matplotlib

### How to Compile Program

#### In Ubuntu

1. Clone this repository

```
git clone git@github.com:akbarmridho/Tucil2_13521093_13521129.git
```

2. Run cmake build

```
cmake -B build .
```

3. Go to bin directory
```
cd build
```

4. Make executable file
```
make
```

#### In Windows

1. Clone this repository

```
git clone git@github.com:akbarmridho/Tucil2_13521093_13521129.git
```

2. Run cmake build

```
cmake -B build . -G "MinGW Makefiles"
```

3. Go to bin directory
```
cd build
```

4. Make executable file
```
mingw32-make
```

### How to Run Program

We provide two version of binary files. The first one was compiled in Ubuntu 22.04 with GNU G++ compiler and the second one was compiled in Windows 11 with MinGW compiler.

In folder bin, run the executable file.

```
cd bin
./Tucil2_13521093_13521129
```

or

```
cd bin
.\Tucil2_13521093_13521129.exe
```

### How To Visualize Result in 3D Scatter Plot
NOTE: Visualization can only be done in three dimensional space. </br>
1. Go to src directory
```
cd src
```

2. Run the python script provided
```
python3 visualizer.py
```