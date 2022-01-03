#ifndef WINDOW_H
#define WINDOW_H

#include <functional>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

class Window
{
public:
    Window(std::function<void()> callback);
    ~Window();
    void main_loop();

private:
    std::function<void()> m_callback;
    GLFWwindow* window;
};

#endif