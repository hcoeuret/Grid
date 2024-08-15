#include <iostream>
#include <SDL2/SDL.h>
#include "Grid.h"
#include "DisplaySystem.h"

using namespace std;

int main()
{
    Grid sampleGrid;
    sampleGrid.DisplayGrid();

    DisplaySystem GridDisplaySystem;


    //event loop stopper
    bool quit = false;
    // Event handler
    SDL_Event e;

    // While the application is running
    while (!quit) {
        // Handle events on the queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit (when window is closed)
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(GridDisplaySystem.getRenderer(), 0, 100, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(GridDisplaySystem.getRenderer());
        // Update the screen
        SDL_RenderPresent(GridDisplaySystem.getRenderer());
    }
    SDL_DestroyWindow(GridDisplaySystem.getWindow());

    SDL_Quit();
}