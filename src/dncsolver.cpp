#include "datatypes.h"
#include "dncsolver.h"
#include "sorter.h"
#include "euclidean.h"
#include "bfsolver.h"
#include <cmath>

closest_pair_t closest_pair_divide_conquer(points_t &points, int depth)
{
    bool lastDims = points[0].size() - 1 == depth;

    /*
     * Base case
     *
     * Jika banyaknya titik kurang dari sama dengan tiga atau hasil proyeksi bersisa satu dimensi,
     * cari solusi pasangan titik terdekat dengan mengugnakan metode brute force
     */
    if (points.size() <= 3 || lastDims)
    {
        return closest_pair_brute_force(points, true);
    }

    /*
     * Lakukan sort berdasarkan axis tertentu, terurut membesar
     * Memiliki kompleksitas waktu O(NlogN)
     */
    quicksort(points, depth);

    int median_idx = points.size() / 2;

    /*
     * Bagi titik menjadi dua bagian, S1 dan S2 berdasarkan median
     */
    auto points_s1 = points_t(points.begin(), points.begin() + median_idx);
    auto points_s2 = points_t(points.begin() + median_idx + 1, points.end());

    /*
     * Divide step,
     *
     * panggil fungsi rekursif dengan titik-titik telah dibagi dua
     *
     * Kompleksitas waktu 2*T(N/2, d) dengan d adalah dimensi
     */
    auto [s1_pairs_list, s1_dist] = closest_pair_divide_conquer(points_s1, depth);
    auto [s2_pairs_list, s2_dist] = closest_pair_divide_conquer(points_s2, depth);

    double delta;
    pairs_t pairs_list;

    // cari delta dan pasangan titik terdekat berdasarkan hasil divide

    if (s1_dist < s2_dist)
    {
        delta = s1_dist;
        pairs_list = s1_pairs_list;
    }
    else if (s1_dist > s2_dist)
    {
        delta = s2_dist;
        pairs_list = s2_pairs_list;
    }
    else
    {
        delta = s1_dist;
        pairs_list = s1_pairs_list;
        combine_pairs(pairs_list, s2_pairs_list);
    }

    point_t median_point = points[median_idx];

    // conquer step
    // pada axis tertentu, ambil titik titik yang pada axis tertentu memenuhi
    // x_i - x_median < delta

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

    /*
     * Conquer step
     *
     * for every points that are closer than delta in an axis,
     * project the points into some axis
     *
     * This step have time complexity
     * T(N, d-1)
     */
    auto [s12_pairs_list, s12_dist] = closest_pair_divide_conquer(points_s12, depth + 1);

    /*
     * Bandingkan delta dengan titik terdekat pada hasil conquer, lalu pilih jarak dan pasangan titik terdekat
     */
    if (s12_dist == delta)
    {
        combine_pairs(pairs_list, s12_pairs_list);
        return closest_pair_t{pairs_list, delta};
    }
    else if (s12_dist < delta)
    {
        return closest_pair_t{s12_pairs_list, s12_dist};
    }

    return closest_pair_t{pairs_list, delta};
}