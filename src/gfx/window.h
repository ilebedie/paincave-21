#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <cstdlib>

#include "gfx.h"
#include "../world/world.h"


/*
    Window(OpenGL init, swap buffer, Input(mouse, keyboard)) live here 
    Window runs main loop
*/
class Window
{
public:
    Window();
    ~Window();
    void main_loop(World& w);

private:
    GLFWwindow* window;
};

#endif