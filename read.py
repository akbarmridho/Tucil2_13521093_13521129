import time
import numpy as np
from src import *

def read_file(path):
    f = open(path, "r")
    points = f.readlines()
    for i in range(len(points)):
        points[i] = points[i].strip().split()
        
    points = np.asarray(points).astype(float)
    return points

if __name__ == "__main__":
    points = read_file("./fails/1.txt")

    print("\nDivide and Conquer O(N(logN)^(k-1))")
    t1 = time.time()
    point1, point2, result1 = get_closest_pair(points.copy())
    t2 = time.time()
    printPoint(point1)
    printPoint(point2)
    print(f"Closest distance {result1} calculated in {t2-t1:.4f} seconds")

    print("\nBrute Force")
    t3 = time.time()
    p1, p2, result2 = brute_force(points.copy())
    # result2 = brute_force_numba(points.copy())
    t4 = time.time()
    printPoint(p1)
    printPoint(p2)
    print(f"Closest distance {result2} calculated in {t4-t3:.4f} seconds")
