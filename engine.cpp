#include "engine.h"

// Constructor
Engine::Engine () {
    fps = DEFAULT_FPS;
}

// Core Functions
void Engine::setDisplay (Display *d) {
    display = d;
}

void Engine::init () {
    al_init();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    display = new Display (size_x, size_y);
    al_init_timeout(&timeout, 0.8);
    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_display_event_source(display->getDisplay()));
}

void Engine::engineQuit() {
    display->del();
}

void Engine::engineTick() {
    ALLEGRO_EVENT ev;
    while (1) {   
        if (!al_wait_for_event_until(queue, &ev, &timeout)) { break; }
        switch (ev.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                display->setClosed(true);
                setState(EQUIT);
                break;
            case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
                printf("Lost Focus\n");
                display->setActive(false);
                setState(EPAUSED);
                break;
            case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
                printf("Gained Focus\n");
                display->setActive(true);
                setState(ERUNNING);
                break;
        }
    }

    if (state == EPAUSED) { return; } //And now we quit if theres nothing todo

    for (int i=0; i < tickables.size(); i++) {
        if (!tickables[i]->tick()) {
            printf("Tick failed for tickable w/ ID #%d", i);
        }
    }
}

void Engine::engineRender() {
    if (state == EPAUSED) {return;}
    display->renderEvents();
    //al_draw_text(font, al_map_rgb(0, 0, 0), 0, 15, 0, "Test");
    display->render();
}

void Engine::engineSleep() {
    if (state == EPAUSED) {
        return engineSleep(0.1); //Slower tick rate when the game is in the background
    }
    engineSleep(1/fps);
}

void Engine::engineSleep(float s) { al_rest(s); }

// Modifiers
void Engine::setFps(int i) { fps = i; }
int Engine::getFps() { return fps; }
void Engine::setState(EngineState s) { state = s; }
EngineState Engine::getState() { return state; }

int Engine::findTickable(Tickable *t) {
    for (int i=0; i < tickables.size(); i++) {
        if (tickables[i] == t) {
            return i;
        }
    }
    return -1;
}

void Engine::addTickable(Tickable *t) {
    tickables.push_back(t);
}

void Engine::rmvTickable(Tickable *t) {
    tickables.erase(tickables.begin()+findTickable(t));
}

void Engine::addSprite(BaseSprite *s) {
    addTickable(s);
    display->addRenderable(s);
}

void Engine::rmvSprite(BaseSprite *s) {
    rmvTickable(s);
    display->rmvRenderable(s);
}