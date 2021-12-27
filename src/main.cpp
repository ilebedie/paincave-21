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

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(800, 800, "paincave-21", nullptr, nullptr);
    if (window == NULL) {
        cout<<"failed to create a window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }


    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
