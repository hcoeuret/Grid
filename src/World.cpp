#include "World.h"

World::World()
{
    currentGrid = Grid(SCREEN_WIDTH/PIXELSIZE, SCREEN_HEIGHT/PIXELSIZE);
    nextGrid = Grid(SCREEN_WIDTH/PIXELSIZE, SCREEN_HEIGHT/PIXELSIZE);
}

void World::ComputeTick()
{
    currentGrid.ComputeNextGrid(nextGrid);
    currentGrid = nextGrid;

}

void World::initWorld()
{
    currentGrid.DisplayGrid();
    currentGrid.SetPixelAtLocation(96,54,125);
}
