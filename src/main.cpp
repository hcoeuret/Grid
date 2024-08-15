#include <iostream>
#include <SDL2/SDL.h>
#include "Grid.h"
#include "DisplaySystem.h"

using namespace std;

int main()
{
    //create world
    Grid sampleGrid(7,7);
    sampleGrid.DisplayGrid();

    //Initialize SDL display 
    DisplaySystem GridDisplaySystem;

    //Enter the infinite render loop
    GridDisplaySystem.RenderLoop();

    //SDL_cleaner
    SDL_DestroyWindow(GridDisplaySystem.getWindow());
    SDL_Quit();
}