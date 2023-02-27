#include <vector>
#include <tuple>

typedef std::vector<double> point_t;

typedef std::vector<point_t> points_t;

typedef std::tuple<point_t, point_t> point_pair_t;

typedef std::vector<point_pair_t> pairs_t;

typedef std::tuple<pairs_t, double> closest_pair_t;