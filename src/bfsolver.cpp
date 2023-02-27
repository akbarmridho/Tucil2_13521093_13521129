#include "bfsolver.h"
#include "euclidean.h"
using namespace std;

int bf_counter = 0;
int dnc_counter = 0;

closest_pair_t closest_pair_brute_force(points_t &points, bool from_dnc)
{
    int n = points.size();

    double min = 1 << 25;
    int point_1_idx;
    int point_2_idx;
    pairs_t pairs_list;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double distance = calculate_euclidean_distance(points[i], points[j]);

            if (from_dnc)
            {
                dnc_counter++;
            }
            else
            {
                bf_counter++;
            }

            if (distance == min)
            {
                pairs_list.push_back(points_pair(points[i], points[j]));
            }
            else if (distance < min)
            {
                min = distance;
                pairs_list.clear();
                pairs_list.push_back(points_pair(points[i], points[j]));
            }
        }
    }

    return closest_pair_t{pairs_list, min};
}