#include <iostream>
#include <SDL2/SDL.h>
#include "World.h"
#include "Grid.h"
#include "DisplaySystem.h"
#include "Global.h"

using namespace std;

int main()
{
    //create and init world
    World world;
    //world.initWorld(); //not useful for now

    //Initialize SDL display 
    DisplaySystem GridDisplaySystem;

    //Enter the infinite render loop
    GridDisplaySystem.RenderLoop(world);

    //SDL_cleaner
    SDL_DestroyWindow(GridDisplaySystem.getWindow());
    SDL_Quit();
}