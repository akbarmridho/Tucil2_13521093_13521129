import numpy as np
from numpy.typing import NDArray
from typing import Tuple


def get_closest_pair(points: NDArray, depth: int = 0) -> Tuple[NDArray, NDArray, float]:
    # quicksort(points, depth, 0, len(points) - 1)
    points = points[points[:, depth].argsort()]
    
    if len(points) <= 3:
        current_dist: float = float('inf')
        point1 = points[0]
        point2 = points[1]
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                dist: float = float(np.linalg.norm(points[i]-points[j]))
                if dist < current_dist:
                    point1 = points[i]
                    point2 = points[j]
                    current_dist = dist

        return point1, point2, current_dist

    median_idx: int = len(points)//2
    median = points[median_idx]

    points_s1 = points[:median_idx]
    points_s2 = points[median_idx:]

    point1 = None
    point2 = None

    # divide
    s1_point1, s1_point2, s1_min = get_closest_pair(points_s1, depth)
    s2_point1, s2_point2, s2_min = get_closest_pair(points_s2, depth)

    delta = min(s1_min, s2_min)

    if s1_min < s2_min:
        point1 = s1_point1
        point2 = s1_point2
    else:
        point1 = s2_point1
        point2 = s2_point2

    # conquer
    points_pm_delta = points[[
        abs(point[depth] - median[depth]) <= delta for point in points]]

    if points_pm_delta.__len__() <= 1:
        return (point1, point2, delta)

    remaining_dimension = len(points[0]) - depth - 1

    if remaining_dimension == 2:
        # quicksort(points_pm_delta, depth + 1, 0, len(points_pm_delta) - 1)
        points_pm_delta = points_pm_delta[points_pm_delta[:, depth+1].argsort()]
        current_min = delta
        current_point1 = point1
        current_point2 = point2

        for i in range(min(6, len(points_pm_delta)), len(points_pm_delta)):
            for j in range(max(0, i-6), i):
                if points_pm_delta[i][depth] - points_pm_delta[j][depth] > current_min:
                    continue
                min_dist: float = float(np.linalg.norm(
                    points_pm_delta[i] - points_pm_delta[j]))
                if min_dist < current_min:
                    current_min = min_dist
                    current_point1 = points_pm_delta[i]
                    current_point2 = points_pm_delta[j]

        return (current_point1, current_point2, current_min)

    pm_point1, pm_point2, pm_min = get_closest_pair(points_pm_delta, depth+1)

    if (pm_min < delta):
        return (pm_point1, pm_point2, pm_min)
    else:
        return (point1, point2, delta)

def quicksort(points: NDArray, depth: int, low: int, high: int):
    # partition
    pivot_depth_val = points[(low + high) // 2, depth] # pivot dengan elemen tengah
    left_ptr = low
    right_ptr = high
    
    while (left_ptr <= right_ptr):
        while (points[left_ptr, depth] < pivot_depth_val):
            left_ptr += 1
        while (points[right_ptr, depth] > pivot_depth_val):
            right_ptr -= 1
        if (left_ptr <= right_ptr):
            temp = points[left_ptr].copy()
            points[left_ptr] = points[right_ptr].copy()
            points[right_ptr] = temp.copy()
            left_ptr += 1
            right_ptr -= 1
    
    # recursion
    if (low < left_ptr - 1):
        quicksort(points, depth, low, left_ptr - 1)
    if (left_ptr < high):
        quicksort(points, depth, left_ptr, high)