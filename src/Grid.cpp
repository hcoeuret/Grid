#include <iostream>

#include "Grid.h"

using namespace std;

//intialize Grid with a 2D vector of size 3x3 by default
Grid::Grid(int RowNumber, int ColumnNumber)
{
    mGrid = std::vector<std::vector<int>>(ColumnNumber, std::vector<int>(RowNumber, 0));
}

 

void Grid::DisplayGrid()
{
    for (const auto& row : mGrid) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}