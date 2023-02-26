#include "euclidean.h"
#include <cmath>

double calculate_euclidean_distance(point_t &a, point_t &b)
{
    double squared_sum = 0.0;
    int dimension = a.size();

    for (int i = 0; i < dimension; i++)
    {
        squared_sum += pow((a[i] - b[i]), 2);
    }

    return sqrt(squared_sum);
}