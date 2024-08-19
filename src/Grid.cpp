#include <iostream>

#include "Grid.h"
#include "Global.h"

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
    if(Row > (SCREEN_HEIGHT/PIXELSIZE -1)|| Row < 0 || (Column > SCREEN_WIDTH/PIXELSIZE - 1) || Column < 0 ){
        std:cerr << "Writing out of bounds" << std::endl;
        return;
    }
    mGrid[Row][Column] = Value;
}

/*
nextGrid is an out parameter where the next computed state of the grid will be written
*/
void Grid::ComputeNextGrid(Grid& nextGrid)
{
    for(int i = 0 ; i < mGrid.size(); i++)
    {
        for(int j = 0 ; j < mGrid[0].size() ; j++)
        {    
            if(i == 0){
                nextGrid.SetPixelAtLocation(i, j, 0);
            }
            else if((i == mGrid.size()-1 && mGrid[i-1][j] == 0)){
                nextGrid.SetPixelAtLocation(i, j, mGrid[i][j]);
            }
            else{
                nextGrid.SetPixelAtLocation(i, j, mGrid[i-1][j]);  
            }
        }
    }
}
