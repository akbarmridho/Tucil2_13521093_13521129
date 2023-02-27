#include "datatypes.h"

extern int bf_counter;
extern int dnc_counter;

/**
 * Check if two point are equal
 * @param p1
 * @param p2
 * @return
 */
bool compare_point(point_t p1, point_t p2);

/**
 * Check if two point pair are equal
 * @param p1
 * @param p2
 * @return
 */
bool compare_pair(point_pair_t pair1, point_pair_t pair2);

/**
 * Combine unique pair from source to destination
 * @param dest
 * @param source
 */
void combine_pairs(pairs_t &dest, pairs_t &source);

/**
 * Solve closest pair problem with brute force method
 * @param points
 * @param from_dnc
 * @return
 */
closest_pair_t closest_pair_brute_force(points_t &points, bool from_dnc = false);