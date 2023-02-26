from src import *
import numpy as np
from src import *
import time
import os

if __name__ == "__main__":
    for x in range(1000):
        # dimensions = int(input("Dimensions: "))
        # num_of_points = int(input("Number of Points: "))
        # num_range = int(input("Number range (+-): "))
        f = open("points.txt", "a")
        
        # points = generate_points(dimensions, num_of_points, num_range)
        # points = readFile("points.txt")
        points = generate_points(3, 1000, 1000)
        for point in points:
            for i in point:
                f.write(f"{i} ")
            f.write("\n")
        f.close()
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

        if (result1 == result2):
            print(f"\ntry {x + 1} passed")
            if os.path.exists("points.txt"):
                os.remove("points.txt")
        else:
            print(f"\ntry {x + 1} failed")
            break

        # if dimensions == 3 and input(
        #         "Do you want to visualize the result? [yes/no] ").lower() == 'yes':
        #     visualize(points, np.array([point1, point2]))