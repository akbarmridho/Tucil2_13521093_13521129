#include "datatypes.h"

int partition(points_t &points, int depth, int low, int high);

void _quicksort(points_t &points, int depth, int low, int high);

/**
 * Sort points based on some axis with quicksort
 */
void quicksort(points_t &, int);