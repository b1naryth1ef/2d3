#include "game.h"

int main(int argc, char **argv) { 
    al_init();
    al_init_image_addon();
    
    Display d (500, 500);
    Engine g (&d);
    ALLEGRO_BITMAP *bmp = al_load_bitmap("m.png");
    if (!bmp) {
        printf("Could not load bmp!\n");
        return -1;
    }
    BaseSprite s (bmp);

    g.display->addRenderable(&s);
    g.setState(ERUNNING);

    while (1) {
        while (g.getState() == ERUNNING) {
            g.engineTick();
            g.engineRender();
            g.engineSleep();
        }

        printf("BREAK\n");
        if (g.getState() == EPAUSED) {
            while (g.getState() == EPAUSED) {
                g.engineTick();
                g.engineSleep(1);
            }
        }

        if (g.getState() == EQUIT) {
            g.engineQuit();
            break;
        }
    }

    d.del();
    return 0;
}