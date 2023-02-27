#include <vector>
#include <tuple>

typedef std::vector<double> point_t;

typedef std::vector<point_t> points_t;

typedef std::tuple<point_t, point_t> points_pair;

typedef std::vector<points_pair> pairs_t;

typedef std::tuple<pairs_t, double> closest_pair_t;