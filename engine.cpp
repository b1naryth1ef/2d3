#include "engine.h"


int main(int argc, char **argv) { 
    al_init();

    Display d (500, 500);
    Game g (&d);
    TestRenderable r;

    g.display->addRenderable(&r);
    g.setState(RUNNING);

    while (1) {
        while (g.getState() == RUNNING || g.getState() == PAUSED) {
            g.gameTick();
            g.gameRender();
            g.gameSleep();
        }

        if (g.getState() == QUIT) {
            g.gameQuit();
            break;
        }
    }

    d.del();
    return 0;
}