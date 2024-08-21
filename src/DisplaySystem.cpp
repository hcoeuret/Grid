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

    bool leftbuttonPressed = false;

    // While the application is running
    while (!quit) {
        // Handle events on the queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit (when window is closed)
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            // Detect mouse button down event
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                leftbuttonPressed = true;
                printf("Right mouse button pressed at (%d, %d)\n", e.button.x, e.button.y);
            }

            // Detect mouse button up event
            if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT) {
                leftbuttonPressed = false;
                printf("Right mouse button released at (%d, %d)\n", e.button.x, e.button.y);
            }
        }

        // Continuous event while right mouse button is held
        if (leftbuttonPressed) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            world.CreatePixel(x, y);
        }

        

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
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
            if(grid.getGrid()[i][j] == 0){
                SDL_SetRenderDrawColor(renderer, 119, 181, 254, 255);
            }
            else{
                SDL_SetRenderDrawColor(renderer, 198, 166, 100, 255);
            }
            tmp_rect= SDL_Rect{j*PIXELSIZE,i*PIXELSIZE,PIXELSIZE,PIXELSIZE}; //x, y, w, h
            SDL_RenderFillRect(renderer, &tmp_rect);
        }
    }
}

SDL_Renderer *DisplaySystem::getRenderer() const
{
    return renderer;
}
