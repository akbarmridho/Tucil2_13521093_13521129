#include "datatypes.h"

extern int bf_counter;
extern int dnc_counter;

bool compare_point(point_t p1, point_t p2);

bool compare_pair(points_pair p1, points_pair p2);

void combine_pairs(pairs_t &dest, pairs_t &source);

closest_pair_t closest_pair_brute_force(points_t &points, bool from_dnc = false);