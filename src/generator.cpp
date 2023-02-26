#include "generator.h"
#include <iostream>
#include <iomanip>
#include <random>

using std::cout;
using std::endl;
using std::mt19937_64;
using std::random_device;
using std::setprecision;
using std::uniform_real_distribution;

points_t generate_points(int dimensions, int number_of_points, int range)
{
    random_device rd;
    mt19937_64 generator(rd());
    uniform_real_distribution<> distributor(-1 * (range / 2), range / 2);

    points_t points;

    for (int i = 0; i < number_of_points; i++)
    {
        point_t point;
        for (int j = 0; j < dimensions; j++)
        {
            point.push_back(distributor(generator));
        }

        points.push_back(point);
    }

    return points;
}

void print_point(point_t point)
{
    cout << '(' << point[0];
    for (int i = 1; i < point.size(); i++)
    {
        cout << ", " << point[i];
    }
    cout << ')' << endl;
}

void print_result(closest_pair_t closest_pair)
{
    auto &[point1, point2, dist] = closest_pair;

    cout << setprecision(8);

    cout << "Closest Pair: " << endl;
    print_point(point1);
    print_point(point2);

    cout << endl
         << "Closest Distance: " << dist << endl;
}
