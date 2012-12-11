#include "game.h"

Engine g;
Entity jeff;

// A: 1
// W: 23
// S: 19
// D: 4

void handleA (int k, bool down) {
    //jeff.sprite->x += 5;
    if (down) { jeff.applyImpulse(-1, 0); }
}
void handleW (int k, bool down) {
    if (down) { jeff.applyImpulse(0, -1); }
}
void handleS (int k, bool down) {
    if (down) { jeff.applyImpulse(0, 1); }
}
void handleD (int k, bool down) {
    if (down) { jeff.applyImpulse(1, 0); }
}

void handleInput(int inp, bool down) {}

int main(int argc, char **argv) {
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

    jeff.setSprite(&s);
    g.addEntity(&jeff);

    loadFont(1, "visitor2.ttf", 45);
    Text *t = new Text("Testing", 1);
    //t->setActive(false);
    t->pos->x = size_x/2;
    t->pos->y = size_y/2;
    g.display->addRenderable(t);
    //g.addFunc(handleInput);
    g.input.bindKey(1, handleA);
    g.input.bindKey(23, handleW);
    g.input.bindKey(19, handleS);
    g.input.bindKey(4, handleD);

    char title[50] = "Test!";
    g.display->setTitle(title);
    setEngineState(ERUNNING);
    g.engineStart();

    return 0;
}
