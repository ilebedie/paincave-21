#ifndef WORLD_H 
#define WORLD_H

#include "../gfx/renderer.h"

struct World
{
    Renderer renderer;
    void update();
};


#endif