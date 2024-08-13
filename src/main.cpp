#include Grid.h
#include <iostream>
#include "Grid.h"

using namespace std;

int main()
{
    int grid[3][3];

    //init grid
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            grid[i][j] = 0;
        }
    }
    
    //display gridf
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << " " << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}