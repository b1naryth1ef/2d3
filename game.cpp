#include "game.h"

Engine g;
Entity jeff;

// A: 1
// W: 23
// S: 19
// D: 4

void handleInput(int inp, bool down) {}

void tickCall () {
    if (g.input.getKey(1) == DOWN) { jeff.applyImpulse(-100, 0); }
    else if (g.input.getKey(23) == DOWN) { jeff.applyImpulse(0, -100); }
    else if (g.input.getKey(19) == DOWN) { jeff.applyImpulse(0, 100); }
    else if (g.input.getKey(4) == DOWN) { jeff.applyImpulse(100, 0); }
}

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
    t->pos->x = size_x/2;
    t->pos->y = size_y/2;
    g.display->addRenderable(t);
    g.setCallOnTick(tickCall);

    char title[50] = "Test!";
    g.display->setTitle(title);
    setEngineState(ERUNNING);
    g.engineStart();

    return 0;
}
