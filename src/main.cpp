#include <iostream>
#include <chrono>
#include "datatypes.h"
#include "bfsolver.h"
#include "dncsolver.h"
#include "generator.h"
#include "visualizer.h"

using std::cin;
using std::cout;
using std::endl;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

int main()
{
     points_t points_dnc, points_bf;
     int dimensions, num_of_points;

     std::cout << "Dimensions: ";
     std::cin >> dimensions;
     std::cout << "Number of points: ";
     std::cin >> num_of_points;

     int range = 1e4;

     points_t points1 = generate_points(dimensions, num_of_points, range);
     points_t points2 = points1;

     cout << endl
          << "Divide And Conquer" << endl;
     auto start_dnc = high_resolution_clock::now();
     auto dnc_result = closest_pair_divide_conquer(points1, 0);
     auto stop_dnc = high_resolution_clock::now();
     print_result(dnc_result);

     duration<double> dnc_duration = duration_cast<duration<double>>(stop_dnc - start_dnc);
     cout << dnc_duration.count() << " seconds elapsed" << endl;
     cout << dnc_counter << " euclediean comparisons" << endl;

     bf_counter = 0;

     cout << endl
          << "Brute Force" << endl;
     auto start_bf = high_resolution_clock::now();
     auto bf_result = closest_pair_brute_force(points2);
     auto stop_bf = high_resolution_clock::now();
     print_result(bf_result);

     duration<double> bf_duration = duration_cast<duration<double>>(stop_bf - start_bf);
     cout << bf_duration.count() << " seconds elapsed" << endl;
     cout << bf_counter << " euclediean comparisons" << endl;

     if (dimensions == 3)
     {
          auto [p1, p2, dist] = dnc_result;
          visualize(points1, p1, p2);
     }

     return 0;
}