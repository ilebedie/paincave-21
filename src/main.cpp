#include <iostream>
#include "gfx/window.h"
#include "gfx/renderer.h"
#include "world/world.h"

using namespace std;

template<typename... Args>
bool all(Args... args) { return (... && args); }

void testCpp17()
{
    bool b = all(true, true, true, false);
    cout<<"Here\n is b: "<<b;
}

int main()
{
    testCpp17();
    Window window;
    World world;
    window.main_loop(world);
    return 0;
}
