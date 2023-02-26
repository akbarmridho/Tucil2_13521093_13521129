#include "sorter.h"

int partition(points_t &points, int depth, int low, int high)
{
    double pivot_depth_val;
    int left_ptr, right_ptr;
    point_t temp;

    pivot_depth_val = points[(low + high) / 2][depth];
    left_ptr = low;
    right_ptr = high;

    while (left_ptr <= right_ptr)
    {
        while (points[left_ptr][depth] < pivot_depth_val)
        {
            left_ptr++;
        }

        while (points[right_ptr][depth] > pivot_depth_val)
        {
            right_ptr--;
        }

        if (left_ptr <= right_ptr)
        {
            temp = points[left_ptr];
            points[left_ptr] = points[right_ptr];
            points[right_ptr] = temp;
            left_ptr++;
            right_ptr--;
        }
    }

    return left_ptr;
}

void _quicksort(points_t &points, int depth, int low, int high)
{
    int part_idx = partition(points, depth, low, high);

    if (low < part_idx - 1)
    {
        _quicksort(points, depth, low, part_idx - 1);
    }

    if (part_idx < high)
    {
        _quicksort(points, depth, part_idx, high);
    }
}

void quicksort(points_t &points, int depth)
{
    if (points.size() > 1)
    {
        _quicksort(points, depth, 0, points.size() - 1);
    }
}