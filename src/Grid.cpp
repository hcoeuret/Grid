#include <iostream>

#include "Grid.h"

using namespace std;

Grid::Grid()
{

for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            mGrid[i][j] = 0;
        }
    }
}


void Grid::DisplayGrid()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << " " << mGrid[i][j] << " ";
        }
        cout << endl;
    }
}