#include "DisplaySystem.h"
#include "Grid.h"

DisplaySystem::DisplaySystem()
{
    //init SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //create window
    window = SDL_CreateWindow("Grid", 0,0,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if(!window)
    {
        //TODO ERROR HANDLING
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if(!renderer)
    {
        //TODO ERROR HANDLING
    }

}

SDL_Window* DisplaySystem::getWindow() const
{
    return window;
}

void DisplaySystem::RenderLoop()
{
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

        SDL_SetRenderDrawColor(renderer, 0, 100, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        DisplayGrid();


        // Update the screen
        SDL_RenderPresent(renderer);
        
    }
}

void DisplaySystem::DisplayGrid()
{
    SDL_SetRenderDrawColor(renderer, 255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
}

SDL_Renderer *DisplaySystem::getRenderer() const
{
    return renderer;
}
