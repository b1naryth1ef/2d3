#include "engine.h"

int main(int argc, char **argv) { 
    al_init();

    Display d (500, 500);
    TestRenderable r;
    d.addRenderable(&r);
    d.renderEvents();
    d.render();
    d.del();

    return 0;
}