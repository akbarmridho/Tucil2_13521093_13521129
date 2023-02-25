from src import *
import numpy as np
from src import *
import time

if __name__ == "__main__":
    dimensions = int(input("Dimensions: "))
    num_of_points = int(input("Number of Points: "))
    num_range = int(input("Number range (+-): "))

    points = generate_points(dimensions, num_of_points, num_range)

    print("\nDivide and Conquer O(N(logN)^(k-1))")
    t1 = time.time()
    point1, point2, result1 = get_closest_pair(points.copy())
    t2 = time.time()
    printPoint(point1)
    printPoint(point2)
    print(f"Closest distance {result1} calculated in {t2-t1:.4f} seconds")

    print("\nBrute Force")
    t3 = time.time()
    _, _, result2 = brute_force(points.copy())
    t4 = time.time()

    print(f"Closest distance {result2} calculated in {t4-t3:.4f} seconds")

    if dimensions == 3 and input(
            "Do you want to visualize the result? [yes/no] ").lower() == 'yes':
        visualize(points, np.array([point1, point2]))
