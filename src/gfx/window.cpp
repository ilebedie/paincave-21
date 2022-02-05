#include "window.h"
#include <chrono>
using namespace std::chrono_literals;

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const auto now = std::chrono::system_clock::now;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

Window::Window()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "paincave-21", nullptr, nullptr);
    if (window == nullptr) 
    {
        std::cout<<"failed to create a window\n";
        glfwTerminate();
        abort();
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Window::main_loop(World& world)
{
    auto sim_time = now();
    while (!glfwWindowShouldClose(window)) 
    {
        auto current_real_world_time = now();

        processInput(window);

        if(sim_time < current_real_world_time)
        {
            sim_time += 16ms;
            world.update();
            glfwSwapBuffers(window);
        }

        glfwPollEvents();
    }
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
