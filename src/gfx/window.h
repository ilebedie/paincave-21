#ifndef WINDOW_H
#define WINDOW_H

#include <functional>
#include <iostream>
#include <cstdlib>

#include "gfx.h"


/*
    Window(OpenGL init, swap buffer, Input(mouse, keyboard)) live here 
    Window runs main loop
*/
class Window
{
public:
    Window();
    ~Window();
    void main_loop(std::function<void()> world_update);

private:
    GLFWwindow* window;
};

#endif