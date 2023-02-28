#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "datatypes.h"

using namespace std;

/* INPUT */
int input_dimensions();

int input_num_of_points();

/* OUTPUT */
void write_to_file(points_t points, string filename);

void write_to_file(pairs_t pairs, string filename);