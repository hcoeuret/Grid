
#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Grid.h"

/*
The world class handle grid manipulation
*/

class World
{
    private:

    Grid currentGrid;
    Grid nextGrid;

    public: 

    World();

    void ComputeTick();


};

#endif 