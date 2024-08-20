#include <iostream>
#include <random> 

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
    std::cout << std::endl;
}

void Grid::ResetGrid()
{
    for(int i = 0 ; i < mGrid.size(); i++)
    {
        for(int j = 0 ; j < mGrid[0].size(); j++)
        {
            mGrid[i][j] = 0;
        }
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
To compute the next grid, we go through the pixel grid
*/
void Grid::ComputeNextGrid(Grid& nextGrid)
{ 
    
    for(int i = 0 ; i < mGrid.size(); i++)
    {
        for(int j = 0 ; j < mGrid[0].size(); j++)
        {
            //check if pixel has a value
            if(mGrid[i][j]>0){
                //check if we have space under to fall
                if(hasSpaceToFall(i, j)){
                    nextGrid.SetPixelAtLocation(i+1, j, mGrid[i][j]);
                }
                else{ 
                    ComputeNextPixelPosition(i, j, nextGrid);
                }
                
            }
        }
    }
}

bool Grid::hasSpaceToFall(int PixelRowPosition, int PixelColumnPosition) const
{
    bool bSpaceDetected = false;
    for(int i = PixelRowPosition ; i < mGrid.size(); i++){
        if(mGrid[i][PixelColumnPosition]==0){
            bSpaceDetected = true;
        }
    }

    return bSpaceDetected;
}

void Grid::ComputeNextPixelPosition(int PixelRPos, int PixelCPos, Grid& nextGrid) const
{
    // Use a random device to seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    if(PixelRPos < (mGrid.size()-1)){
        if(mGrid[PixelRPos][PixelCPos + 1] == 0 && mGrid[PixelRPos][PixelCPos - 1] == 0){
            if (dis(gen) == 0) {
                nextGrid.SetPixelAtLocation(PixelRPos, PixelCPos +1, mGrid[PixelRPos][PixelCPos]);
            }
            else{
                nextGrid.SetPixelAtLocation(PixelRPos, PixelCPos -1 , mGrid[PixelRPos][PixelCPos]);
            }
        
        }
        if(mGrid[PixelRPos][PixelCPos + 1] > 0 && mGrid[PixelRPos][PixelCPos - 1] == 0){
            nextGrid.SetPixelAtLocation(PixelRPos, PixelCPos, mGrid[PixelRPos][PixelCPos]);
        }
        if(mGrid[PixelRPos][PixelCPos + 1] == 0 && mGrid[PixelRPos][PixelCPos - 1] > 0){
            nextGrid.SetPixelAtLocation(PixelRPos, PixelCPos, mGrid[PixelRPos][PixelCPos]);
        }
        if(mGrid[PixelRPos][PixelCPos + 1] > 0 && mGrid[PixelRPos][PixelCPos - 1] > 0){
            nextGrid.SetPixelAtLocation(PixelRPos, PixelCPos, mGrid[PixelRPos][PixelCPos]);
        }
    }
    else{
        nextGrid.SetPixelAtLocation(PixelRPos, PixelCPos, mGrid[PixelRPos][PixelCPos]);
    }
    
}
