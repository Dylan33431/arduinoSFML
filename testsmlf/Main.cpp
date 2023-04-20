#include "Engine.h"

int main()
{
    Engine engine;

    Game minecraft("minecraft");
    engine.addGame(&minecraft, true);

    while (engine.getIsRunning()) {

        engine.update();
    }

    return 0;
}