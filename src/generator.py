from numpy.typing import NDArray
import numpy as np


def generate_points(dimensions: int, number_of_points: int, range: int = 1000) -> NDArray:
    return np.asarray((np.random.rand(number_of_points, dimensions) - 0.5)*range*2, dtype=int)


def printPoint(point: NDArray):
    print(f"({point[0]}", end="")
    for i in range(1, len(point)):
        print(f", {point[i]}", end="")
    print(")")
