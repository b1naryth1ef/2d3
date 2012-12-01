#include "game.h"

int main(int argc, char **argv) { 
    Engine g;
    g.init();

    ALLEGRO_BITMAP *bmp = al_load_bitmap("test.png");
    if (!bmp) {
        printf("Could not load bmp!\n");
        return -1;
    }

    // Lets create a new sprite from a sprite sheet
    AnimatedSprite s (bmp, .3);
    s.addFrame(0, 0, 16, 16); // This adds a frame (x, y offset and h/w)
    s.addFrame(16, 0, 16, 16); // And another
    ALLEGRO_BITMAP *fexample = s.addFrame(0, 0, 16, 16); // Lets say we store these frames
    s.rmvFrame(fexample); // We can remove them!

    loadFont(1, "visitor2.ttf", 45);
    Text *t = new Text("Testing", getFont(1));
    t->pos->x = size_x/2;
    t->pos->y = size_y/2;
    g.display->addRenderable(t);

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