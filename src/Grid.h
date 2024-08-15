
#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid
{
    private:

        std::vector<std::vector<int>> mGrid;

    public: 

        Grid(int RowNumber = 3, int ColumnNumber = 3);

        void DisplayGrid();

};

#endif 