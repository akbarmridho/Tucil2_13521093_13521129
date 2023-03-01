#include "datatypes.h"

/**
 * Part array of points into two parts using the middle element as its pivot
 */
int partition(points_t &points, int depth, int low, int high);

void _quicksort(points_t &points, int depth, int low, int high);

/**
 * Sort points based on some axis with quicksort
 */
void quicksort(points_t &, int);