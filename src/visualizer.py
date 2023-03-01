import numpy as np
from numpy.typing import NDArray
import matplotlib.pyplot as plt
import itertools

# read log files
def read_file(path):
    f = open(path, "r")
    points = f.readlines()
    for i in range(len(points)):
        points[i] = points[i].strip().split()
        
    points = np.asarray(points).astype(float)
    f.close()
    
    return points

# visualization in 3D scatter plot
def visualize(points: NDArray, pairs_list: NDArray):
    for point in pairs_list:
        new_point = points
        for i in range(len(points)):
            if np.array_equal(points[i], point):
                new_point = np.delete(points, i, axis=0)

        points = new_point

    fig = plt.figure("3D Scatter Plot")
    ax = fig.add_subplot(projection='3d')

    ax.scatter(points[:, 0], points[:, 1], points[:, 2], marker='o')
    
    # change color for each pair of closest points
    colors = itertools.cycle(["tab:orange", "tab:green", "tab:red", "tab:purple", "tab:brown", "tab:pink", "tab:gray", "tab:olive", "tab:cyan", "r", "g", "b", "c", "m", "y", "k"])
    for i in range(0, len(pairs_list), 2):
        pairs_color = next(colors)
        ax.scatter(pairs_list[i, 0], pairs_list[i, 1],
               pairs_list[i, 2], marker='^', color=pairs_color)
        ax.scatter(pairs_list[i + 1, 0], pairs_list[i + 1, 1],
               pairs_list[i + 1, 2], marker='^', color=pairs_color)
    
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')

    plt.show()

# main program for visualization
if __name__ == "__main__":
    points = read_file("../log/points.txt")
    pairs_list = read_file("../log/pairs_list.txt")
    visualize(points, pairs_list)