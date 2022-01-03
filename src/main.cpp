#include <iostream>
#include "gfx/window.h"
#include "gfx/renderer.h"

using namespace std;

template<typename... Args>
bool all(Args... args) { return (... && args); }

void testCpp17() {
    bool b = all(true, true, true, false);
    cout<<"Here\n is b: "<<b;
}

struct World
{
    Renderer renderer;
    void update()
    {
        renderer.update();
    }
};

int main() {
    testCpp17();
    Window window;
    World world;
    auto world_update_callback = std::bind(&World::update, world);
    window.main_loop(world_update_callback);
    return 0;
}
