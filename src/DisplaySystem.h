#ifndef DISPLAYSYTEM_H
#define DISPLAYSYTEM_H
#include <SDL2/SDL.h>
#include "Grid.h"

class DisplaySystem
{
    private:
    SDL_Window * window;
    SDL_Renderer * renderer;

    public:

    DisplaySystem();

    void ClearScreenWithColor();
    void DisplayGrid(const Grid& grid);
    SDL_Renderer* getRenderer() const;
    SDL_Window* getWindow() const;
    void RenderLoop(Grid& grid);

};

#endif