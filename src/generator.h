#include "datatypes.h"

/**
 * Generate uniform real numbers with mt19937_64 engine
 *
 * @param dimensions
 * @param number_of_points
 * @param range
 * @return
 */
points_t generate_points(int dimensions, int number_of_points, int range);

/**
 * Print point to cout
 * @param point
 */
void print_point(point_t point);

/**
 * Print pair result
 * @param closest_pair
 */
void print_result(const closest_pair_t& closest_pair);