
#ifndef GRID_H
#define GRID_H

#include <vector>

/*
Grid object and its operation
*/
class Grid
{
    private:

        std::vector<std::vector<int>> mGrid;

    public: 

        Grid(int RowNumber = 3, int ColumnNumber = 3);
        
        const std::vector<std::vector<int>>& getGrid() const;
        void DisplayGrid() const;
        void ResetGrid();
        void SetPixelAtLocation(int Row, int Column, int Value);
        void ComputeNextGrid(Grid& nextGrid);
        bool hasSpaceToFall(int PixelRowPosition, int PixelColumnPosition) const;
        int ComputeNextPixelPosition(int PixelRowPosition, int PixelColumnPosition) const;
        

};

#endif 