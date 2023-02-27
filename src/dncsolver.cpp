#include "datatypes.h"
#include "dncsolver.h"
#include "sorter.h"
#include "euclidean.h"
#include "bfsolver.h"
#include <cmath>

closest_pair_t base_case(points_t &points)
{
    // Prekondisi: minimal ada dua titik di points
    double current_min, dist;
    pairs_t pairs_list;

    current_min = 1 << 20;

    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            dist = calculate_euclidean_distance(points[i], points[j]);
            dnc_counter++;

            if (dist == current_min)
            {
                pairs_list.push_back(points_pair(points[i], points[j]));
            }
            else if (dist < current_min)
            {
                current_min = dist;
                pairs_list.clear();
                pairs_list.push_back(points_pair(points[i], points[j]));
            }
        }
    }

    return closest_pair_t{pairs_list, current_min};
}

closest_pair_t closest_pair_divide_conquer(points_t &points, int depth)
{
    if (points.size() <= 3)
    {
        return base_case(points);
    }

    if (points[0].size() - depth == 1)
    {
        return closest_pair_brute_force(points, true);
    }

    quicksort(points, depth);

    int median_idx = points.size() / 2;

    auto points_s1 = points_t(points.begin(), points.begin() + median_idx);
    auto points_s2 = points_t(points.begin() + median_idx + 1, points.end());

    // divide step
    auto [s1_pairs_list, s1_dist] = closest_pair_divide_conquer(points_s1, depth);
    auto [s2_pairs_list, s2_dist] = closest_pair_divide_conquer(points_s2, depth);

    double delta;
    pairs_t pairs_list;

    if (s1_dist < s2_dist)
    {
        delta = s1_dist;
        pairs_list = s1_pairs_list;
    }
    else if (s1_dist < s2_dist)
    {
        delta = s2_dist;
        pairs_list = s2_pairs_list;
    }
    else
    {
        delta = s1_dist;
        pairs_list.insert(pairs_list.end(), s1_pairs_list.begin(), s1_pairs_list.end());
        pairs_list.insert(pairs_list.end(), s2_pairs_list.begin(), s2_pairs_list.end());
    }

    point_t median_point = points[median_idx];

    points_t points_s12;

    for (auto &point : points)
    {
        if (std::abs(point[depth] - median_point[depth]) < delta)
        {
            points_s12.push_back(point);
        }
    }

    if (points_s12.size() <= 1)
    {
        return closest_pair_t{pairs_list, delta};
    }

    // conquer step
    double s12_dist;
    point_t s12_point1, s12_point2;
    pairs_t s12_pairs_list;
    
    auto [s12_pairs_list, s12_dist] = closest_pair_divide_conquer(points_s12, depth + 1);

    if (s12_dist == delta)
    {
        pairs_list.insert(pairs_list.end(), s12_pairs_list.begin(), s12_pairs_list.end());
        return closest_pair_t{pairs_list, delta};
    }
    else if (s12_dist < delta)
    {
        return closest_pair_t{s12_pairs_list, s12_dist};
    }

    return closest_pair_t{pairs_list, delta};
}