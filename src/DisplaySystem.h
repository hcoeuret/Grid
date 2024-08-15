#ifndef DISPLAYSYTEM_H
#define DISPLAYSYTEM_H
#include <SDL2/SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class DisplaySystem
{
    private:
    SDL_Window * window;
    SDL_Renderer * renderer;

    public:

    DisplaySystem();

    void ClearScreenWithColor();
    void DisplayGrid(class Grid * Grid);
    SDL_Renderer* getRenderer() const;
    SDL_Window* getWindow() const;

};

#endif