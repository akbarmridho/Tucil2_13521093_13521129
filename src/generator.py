from numpy.typing import NDArray
import numpy as np


# def read_file(path):
#     f = open(path, "r")
#     points = f.readlines()
#     for i in range(len(points)):
#         points[i] = points[i].strip().split()
        
#     points = np.asarray(points).astype(float)
#     return points

def generate_points(dimensions: int, number_of_points: int, range: int = 1000) -> NDArray:
    return np.asarray((np.random.rand(number_of_points, dimensions) - 0.5)*range*2, dtype=int).astype(np.float64)


def printPoint(point: NDArray):
    print(f"({point[0]}", end="")
    for i in range(1, len(point)):
        print(f", {point[i]}", end="")
    print(")")