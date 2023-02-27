#include "bfsolver.h"
#include "euclidean.h"
using namespace std;

int bf_counter = 0;
int dnc_counter = 0;

bool compare_point(point_t p1, point_t p2)
{
    bool equal = true;
    int i = 0;
    int dims = p1.size();

    while (i < dims && equal)
    {
        if (p1[i] != p2[i])
        {
            equal = false;
        }

        i++;
    }

    return equal;
}

bool compare_pair(points_pair pair1, points_pair pair2)
{
    auto [p11, p12] = pair1;
    auto [p21, p22] = pair2;

    return (compare_point(p11, p21) && compare_point(p12, p22)) ||
           (compare_point(p11, p22) && compare_point(p12, p21));
}

void combine_pairs(pairs_t &dest, pairs_t &source)
{
    for (auto &src : source)
    {
        int i = 0;
        bool match = false;

        while (i < dest.size() && !match)
        {
            auto to_cmp = dest[i];

            if (!compare_pair(src, to_cmp))
            {
                dest.push_back(src);
            }

            i++;
        }
    }
}

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