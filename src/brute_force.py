import numpy as np
from numpy.typing import NDArray


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
