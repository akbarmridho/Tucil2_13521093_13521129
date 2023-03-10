#include <iostream>
#include <chrono>
#include "datatypes.h"
#include "bfsolver.h"
#include "dncsolver.h"
#include "generator.h"
#include "io.h"

using std::cin;
using std::cout;
using std::endl;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

bool run(int dimension, int n, bool debug = false)
{
     bf_counter = 0;
     dnc_counter = 0;

     int range = 1e4;
     points_t points1 = generate_points(dimension, n, range);
     if (dimension == 3)
     {
          write_to_file(points1, "../log/points.txt");
     }

     points_t points2 = points1;

     if (debug)
     {
          cout << endl
               << "Dims " << dimension << " num of points " << n << endl;
     }

     cout << endl
          << "Divide And Conquer" << endl;
     auto start_dnc = high_resolution_clock::now();
     auto dnc_result = closest_pair_divide_conquer(points1, 0);
     auto stop_dnc = high_resolution_clock::now();
     print_result(dnc_result);

     duration<double> dnc_duration = duration_cast<duration<double>>(stop_dnc - start_dnc);
     cout << dnc_duration.count() << " seconds elapsed" << endl;
     cout << dnc_counter << " euclidean distance comparisons" << endl;

     bf_counter = 0;

     cout << endl
          << "Brute Force" << endl;
     auto start_bf = high_resolution_clock::now();
     auto bf_result = closest_pair_brute_force(points2);
     auto stop_bf = high_resolution_clock::now();
     print_result(bf_result);

     duration<double> bf_duration = duration_cast<duration<double>>(stop_bf - start_bf);
     cout << bf_duration.count() << " seconds elapsed" << endl;
     cout << bf_counter << " euclidean distance comparisons" << endl;

     if (dimension == 3 && !debug)
     {
          auto [pairs_list, dist] = dnc_result;
          write_to_file(pairs_list, "../log/pairs_list.txt");
     }

     auto [dncres, dncdist] = dnc_result;
     auto [bfres, bfdist] = bf_result;

     return dncdist == bfdist;
}

int main()
{
     // DEBUG PURPOSES
     bool DEBUG = false;

     if (DEBUG)
     {
          bool shouldStop = false;
          int counter = 0;
          int limit = 100;

          while (!shouldStop)
          {
               int dims[] = {1, 2, 3, 4, 5};
               int ns[] = {10, 32, 128, 1000, 2000};

               int i = 0;

               while (i < 5 && !shouldStop)
               {
                    int j = 0;
                    while (j < 5 && !shouldStop)
                    {
                         bool correctResult = run(dims[i], ns[j], true);

                         if (!correctResult)
                         {
                              shouldStop = true;
                         }
                         j++;
                         counter++;

                         if (counter == limit)
                         {
                              shouldStop = true;
                         }
                    }
                    i++;
               }
          }

          if (counter < limit)
          {

               cout << "Total " << counter << " run before error" << endl;
          }
          else
          {
               cout << "No errors found within " << limit << " run" << endl;
          }
     }
     else
     {
          int dimensions, num_of_points;

          dimensions = input_dimensions();
          num_of_points = input_num_of_points();

          run(dimensions, num_of_points);
     }

     return 0;
}