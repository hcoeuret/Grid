#include <iostream>
#include <SDL2/SDL.h>
#include "Grid.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

using namespace std;

int main()
{
    Grid sampleGrid;
    sampleGrid.DisplayGrid();

    //init SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //create window
    SDL_Window * window = SDL_CreateWindow("Grid", 0,0,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if(!window)
    {
        //TODO ERROR HANDLING
    }

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if(!renderer)
    {
        //TODO ERROR HANDLING
    }

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

        // Clear screen with black color
        SDL_SetRenderDrawColor(renderer, 0, 100, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        // Update the screen
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);

    SDL_Quit();
}