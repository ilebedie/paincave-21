#include <iostream>
#include "gfx/window.h"
#include "gfx/renderer.h"
#include "world/world.h"

using namespace std;

int main()
{
    Window window;
    World world;
    window.main_loop(world);
    return 0;
}
