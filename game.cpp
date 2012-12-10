#include "game.h"

void handleInput(int inp, bool down) {
    printf("Success %d!\n", inp);
}

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

    // And now a friendly entity to hold that sprite
    Entity jeff;
    jeff.setSprite(&s);

    g.addEntity(&jeff);

    loadFont(1, "visitor2.ttf", 45);
    Text *t = new Text("Testing", 1);
    //t->setActive(false);
    t->pos->x = size_x/2;
    t->pos->y = size_y/2;
    g.display->addRenderable(t);
    g.addFunc(handleInput);

    char title[50] = "Test!";
    g.display->setTitle(title);
    setEngineState(ERUNNING);
    g.engineStart();

    return 0;
}