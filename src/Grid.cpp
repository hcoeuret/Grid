#include <iostream>

#include "Grid.h"

using namespace std;

//intialize Grid with a 2D vector of size 3x3 by default
Grid::Grid(int RowNumber, int ColumnNumber)
{
    mGrid = std::vector<std::vector<int>>(RowNumber, std::vector<int>(ColumnNumber, 0));
}

const std::vector<std::vector<int>>& Grid::getGrid() const
{
    return mGrid;
}

void Grid::DisplayGrid() const
{
    for (const auto& row : mGrid) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::SetPixelAtLocation(int Row, int Column, int Value)
{
    mGrid[Row][Column] = Value;
}

void Grid::ComputeTick()
{
    for(int i = mGrid.size()-1 ; i > 0; i--)
    {
        for(int j = mGrid[0].size() ; j > 0 ; j--)
        {
            if(mGrid[i][j]>0 ){
                mGrid[i][j+1]=mGrid[i][j];
                mGrid[i][j]=0;
            }
        }
    }
}

//&& (i < (mGrid[0].size()-1)