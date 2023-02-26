#include "bfsolver.h"
#include "euclidean.h"

closest_pair_t closest_pair_brute_force(points_t &points)
{
    int n = points.size();

    double min = 1 << 25;
    int point_1_idx;
    int point_2_idx;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double distance = calculate_euclidean_distance(points[i], points[j]);

            if (distance < min)
            {
                point_1_idx = i;
                point_2_idx = j;
                min = distance;
            }
        }
    }

    return closest_pair_t{points[point_1_idx], points[point_2_idx], min};
}