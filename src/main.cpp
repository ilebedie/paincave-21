#include <iostream>
#include "gfx/window.h"

using namespace std;

template<typename... Args>
bool all(Args... args) { return (... && args); }

void testCpp17() {
    bool b = all(true, true, true, false);
    cout<<"Here\n is b: "<<b;
}

void render()
{
    // render
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main() {
    testCpp17();
    Window window(render);
    window.main_loop();
    return 0;
}
