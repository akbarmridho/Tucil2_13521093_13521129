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
    point_t point1, point2;

    current_min = 1 << 20;

    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            dist = calculate_euclidean_distance(points[i], points[j]);
            dnc_counter++;
            point1 = points[i];
            point2 = points[j];

            if (dist < current_min)
            {
                current_min = dist;
            }
        }
    }

    return closest_pair_t{point1, point2, current_min};
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
    auto [s1_point1, s1_point2, s1_dist] = closest_pair_divide_conquer(points_s1, depth);
    auto [s2_point1, s2_point2, s2_dist] = closest_pair_divide_conquer(points_s2, depth);

    double delta;
    point_t point1;
    point_t point2;

    if (s1_dist < s2_dist)
    {
        delta = s1_dist;
        point1 = s1_point1;
        point2 = s1_point2;
    }
    else
    {
        delta = s2_dist;
        point1 = s2_point1;
        point2 = s2_point2;
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
        return closest_pair_t{point1, point2, delta};
    }

    // conquer step
    double s12_dist;
    point_t s12_point1, s12_point2;

    auto [a, b, c] = closest_pair_divide_conquer(points_s12, depth + 1);
    s12_point1 = a;
    s12_point2 = b;
    s12_dist = c;

    if (s12_dist < delta)
    {
        return closest_pair_t{s12_point1, s12_point2, s12_dist};
    }

    return closest_pair_t{point1, point2, delta};
}