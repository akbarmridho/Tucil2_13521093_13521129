#include "io.h"

/* INPUT */
int input_dimensions()
{
    int dims;

    do
    {
        cin >> dims;

        if (dims < 1)
        {
            cout << "Invalid dimensions." << endl;
        }
    }
    while (dims < 1);
    
    return dims;
}

int input_num_of_points()
{
    int num_of_points;
    
    do
    {
        cin >> num_of_points;

        if (num_of_points < 2)
        {
            cout << "Invalid number of points. There should be at least two points." << endl;
        }
    }
    while (num_of_points < 2);
    
    return num_of_points;
}

/* OUTPUT */
void write_to_file(points_t points, string filename)
{   
    filesystem::remove(filename);

    ofstream file(filename);

    for (int i = 0; i < points.size(); i++)
    {
        for (int j = 0; j < points[0].size(); j++)
        {
            file << points[i][j] << " ";
        }
        file << "\n";
    }

    file.close();
}

void write_to_file(pairs_t pairs, string filename)
{
    filesystem::remove(filename);

    ofstream file(filename);

    for (int i = 0; i < pairs.size(); i++)
    {
        for (int j = 0; j < get<0>(pairs[0]).size(); j++)
        {
            file << get<0>(pairs[i])[j] << " ";
        }
        file << "\n";

        for (int j = 0; j < get<0>(pairs[0]).size(); j++)
        {
            file << get<1>(pairs[i])[j] << " ";
        }
        file << "\n";
    }
    
    file.close();
}