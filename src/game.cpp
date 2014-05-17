#include "game.h"


Engine g;
Entity jeff;

// A: 1
// W: 23
// S: 19
// D: 4

void handleInput(int inp, bool down) {
    DEBUG("Key code: %i", inp);
    if (inp == 17) {
        g.setEngineState(EQUIT);
    } else if (inp == 18) {
        jeff.setPosition(0, 0);
    }
}

void tickCall () {
    if (g.input.getKey(1) == DOWN) { jeff.applyImpulse(-100, 0); }
    if (g.input.getKey(23) == DOWN) { jeff.applyImpulse(0, -100); }
    if (g.input.getKey(19) == DOWN) { jeff.applyImpulse(0, 100); }
    if (g.input.getKey(4) == DOWN) { jeff.applyImpulse(100, 0); }
}

int main(int argc, char **argv) {
    g.init();

    ALLEGRO_BITMAP *bmp = al_load_bitmap("./res/test.png");
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

    loadFont(1, "./res/visitor2.ttf", 45);
    Text *t = new Text("Testing", 1);
    t->pos->x = size_x/2;
    t->pos->y = size_y/2;
    g.display->addRenderable(t);
    g.setCallOnTick(tickCall);

    // Bind "q" to reset
    g.input.bindChar('q', handleInput);
    g.input.bindChar('r', handleInput);

    //char title[50] = "Test!";
    g.display->setTitle(std::string("Test!"));
    g.setEngineState(ERUNNING);
    g.engineStart();

    return 0;
}
