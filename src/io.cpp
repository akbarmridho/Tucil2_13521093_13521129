#include "io.h"

/* INPUT */
int input_dimensions()
{
    int dims;

    do
    {
        cout << "Dimensions: ";
        cin >> dims;

        if (dims < 1)
        {
            cout << "Invalid dimensions. Please try again." << endl;
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
        cout << "Number of points: ";
        cin >> num_of_points;

        if (num_of_points < 2)
        {
            cout << "Invalid number of points. There should be at least two points. Please try again." << endl;
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
    int dims = points[0].size();
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = 0; j < dims; j++)
        {
            file << points[i][j];
            if (j != dims - 1)
            {
                file << " ";
            }
        }
        file << "\n";
    }

    file.close();
}

void write_to_file(pairs_t pairs, string filename)
{
    filesystem::remove(filename);

    ofstream file(filename);
    int dims = get<0>(pairs[0]).size();
    for (int i = 0; i < pairs.size(); i++)
    {
        for (int j = 0; j < dims; j++)
        {
            file << get<0>(pairs[i])[j];
            if (j != dims - 1)
            {
                file << " ";
            }
        }
        file << "\n";

        for (int j = 0; j < dims; j++)
        {
            file << get<1>(pairs[i])[j];
            if (j != dims - 1)
            {
                file << " ";
            }
        }
        file << "\n";
    }
    
    file.close();
}