#include "World.h"

World::World()
{
    currentGrid =Grid(SCREEN_HEIGHT/PIXELSIZE - 7, SCREEN_WIDTH/PIXELSIZE);

    nextGrid = Grid(SCREEN_HEIGHT/PIXELSIZE - 7, SCREEN_WIDTH/PIXELSIZE);
}

void World::ComputeTick()
{
    nextGrid.ResetGrid();
    currentGrid.ComputeNextGrid(nextGrid);
    currentGrid = nextGrid;
    

}

void World::initWorld()
{
    /*debug*/
    /*
    currentGrid.SetPixelAtLocation(6,3,1);
    currentGrid.SetPixelAtLocation(3,4,1);
    currentGrid.SetPixelAtLocation(6,5,1);
    currentGrid.SetPixelAtLocation(6,4,1);

    ComputeTick();
    currentGrid.DisplayGrid();
    ComputeTick();
    currentGrid.DisplayGrid();
    ComputeTick();
    currentGrid.DisplayGrid();
    ComputeTick();
    currentGrid.DisplayGrid();
    ComputeTick();
    currentGrid.DisplayGrid();
    ComputeTick();
    currentGrid.DisplayGrid();
    */
   
    currentGrid.SetPixelAtLocation(54,96,125);
    currentGrid.SetPixelAtLocation(52,96,125);
    currentGrid.SetPixelAtLocation(50,96,125);
    currentGrid.SetPixelAtLocation(48,96,125);
    currentGrid.SetPixelAtLocation(23,78,125);
    currentGrid.SetPixelAtLocation(78,20,125);
    
    
}
