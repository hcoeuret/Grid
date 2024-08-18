#include "World.h"

World::World()
{
    currentGrid = Grid();
    nextGrid = Grid();
}

void World::ComputeTick()
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
