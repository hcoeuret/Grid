#include <vector>
#include "DisplaySystem.h"



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

void DisplaySystem::RenderLoop(World& world)
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

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        world.ComputeTick();
        DisplayGrid(world.getCurrentGrid());

        // Update the screen
        SDL_RenderPresent(renderer);
        SDL_Delay(TICK_DELAY);
        
    }
}

void DisplaySystem::DisplayGrid(const Grid& grid)
{
    SDL_Rect tmp_rect; //x, y, w, h
    for(int i = 0 ; i < grid.getGrid().size(); i++){
        for(int j = 0 ; j < grid.getGrid()[0].size() ; j++){
            SDL_SetRenderDrawColor(renderer, grid.getGrid()[i][j], grid.getGrid()[i][j], grid.getGrid()[i][j], 255);  // Red rectangle
            tmp_rect= SDL_Rect{j*PIXELSIZE,i*PIXELSIZE,PIXELSIZE,PIXELSIZE}; //x, y, w, h
            SDL_RenderFillRect(renderer, &tmp_rect);
        }
    }
}

SDL_Renderer *DisplaySystem::getRenderer() const
{
    return renderer;
}
