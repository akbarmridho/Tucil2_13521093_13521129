import numpy as np
from numpy.typing import NDArray
from numba import njit  # type: ignore


def brute_force(arrpoints):
    min: float = float('inf')
    iidx = -1
    jidx = -1
    for i in range(len(arrpoints)):
        for j in range(i + 1, len(arrpoints)):
            dist: float = float(np.linalg.norm(arrpoints[i]-arrpoints[j]))
            if dist < min:
                iidx = i
                jidx = j
                min = dist
    return (arrpoints[iidx], arrpoints[jidx], min)


@njit
def brute_force_numba(arrpoints):
    n, _ = arrpoints.shape
    min = 1000.0

    for i in range(n):
        for j in range(i + 1, n):
            diff = arrpoints[i]-arrpoints[j]
            dist = np.linalg.norm(diff)
            if dist < min:
                min = dist

    return min
