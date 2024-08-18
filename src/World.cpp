#include "World.h"

World::World()
{
    currentGrid = Grid(SCREEN_HEIGHT/PIXELSIZE, SCREEN_WIDTH/PIXELSIZE);
    nextGrid = Grid(SCREEN_HEIGHT/PIXELSIZE, SCREEN_WIDTH/PIXELSIZE);
}

void World::ComputeTick()
{
    currentGrid.ComputeNextGrid(nextGrid);
    currentGrid = nextGrid;

}

void World::initWorld()
{
    currentGrid.DisplayGrid();
    currentGrid.SetPixelAtLocation(54,96,125);
}
