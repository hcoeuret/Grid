#include <iostream>
#include <SDL2/SDL.h>
#include "Grid.h"
#include "DisplaySystem.h"

using namespace std;

int main()
{
    //create world
    Grid sampleGrid(192,108);
    sampleGrid.DisplayGrid();
    sampleGrid.SetPixelAtLocation(96,54,125);

    //Initialize SDL display 
    DisplaySystem GridDisplaySystem;

    //Enter the infinite render loop
    GridDisplaySystem.RenderLoop(sampleGrid);

    //SDL_cleaner
    SDL_DestroyWindow(GridDisplaySystem.getWindow());
    SDL_Quit();
}