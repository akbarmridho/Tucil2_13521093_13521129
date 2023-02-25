import matplotlib.pyplot as plt  # type: ignore
import numpy as np
from numpy.typing import NDArray


def visualize(points: NDArray, closest_pairs: NDArray):
    for pair in closest_pairs:
        new_point = points
        for i in range(len(points)):
            if np.array_equal(points[i], pair):
                new_point = np.delete(points, i, axis=0)
                break

        points = new_point

    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')

    ax.scatter(points[:, 0], points[:, 1], points[:, 2], marker='o')
    ax.scatter(closest_pairs[:, 0], closest_pairs[:, 1],
               closest_pairs[:, 2], marker='^', color="#FF0000")

    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')

    plt.show()
