#include "visualizer.h"

using std::vector;
using namespace matplot;

void visualize(points_t &points, point_t &p1, point_t &p2)
{
    vector<double> x, y, z;

    for (int i = 0; i < points.size(); i++)
    {
        if (points[i] != p1 && points[i] != p2)
        {
            x.push_back(points[i][0]);
            y.push_back(points[i][1]);
            z.push_back(points[i][2]);
        }
    }

    x.push_back(p1[0]);
    y.push_back(p1[1]);
    z.push_back(p1[2]);
    x.push_back(p2[0]);
    y.push_back(p2[1]);
    z.push_back(p2[2]);

    vector<double> sizes(x.size(), 2);
    vector<double> colors(x.size() - 2, 1);

    fill_n(back_inserter(colors), 2, 2);

    scatter3(x, y, z, sizes, colors);

    save("result.jpg");

    // show();
}