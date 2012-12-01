#include "game.h"

int main(int argc, char **argv) { 
    al_init();
    al_init_image_addon();
    
    Display d (500, 500);
    Engine g (&d);
    ALLEGRO_BITMAP *bmp = al_load_bitmap("test.png");
    if (!bmp) {
        printf("Could not load bmp!\n");
        return -1;
    }

    // Lets create a new sprite from a sprite sheet
    AnimatedSprite s (bmp, 1);
    s.addFrame(0, 0, 16, 16); // This adds a frame (x, y offset and h/w)
    s.addFrame(16, 0, 16, 16); // And another
    ALLEGRO_BITMAP *fexample = s.addFrame(0, 0, 16, 16); // Lets say we store these frames
    s.rmvFrame(fexample); // We can remove them!

    g.addSprite(&s); // Now lets add the sprite to the game!

    char title[50] = "Test!";
    g.display->setTitle(title);
    g.setState(ERUNNING);

    while (1) {
        while (g.getState() == ERUNNING || g.getState() == EPAUSED) {
            g.engineTick();
            g.engineRender();
            g.engineSleep();
        }

        if (g.getState() == EQUIT) {
            g.engineQuit();
            break;
        }
    }

    //d.del();
    return 0;
}