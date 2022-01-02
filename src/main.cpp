#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

template<typename... Args>
bool all(Args... args) { return (... && args); }

void testCpp17() {
    bool b = all(true, true, true, false);
    cout<<"Here\n is b: "<<b;
}

// to renderer
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// to renderer
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
// most of this goes to renderer
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "paincave-21", nullptr, nullptr);
    if (window == nullptr) {
        cout<<"failed to create a window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window)) {
        // input
        processInput(window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // swap
        glfwSwapBuffers(window);

        // poll
        glfwPollEvents();
    }


    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
