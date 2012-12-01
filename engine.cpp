#include "engine.h"

// Constructor
Engine::Engine (Display *d) {
    display = d;
    fps = DEFAULT_FPS;
    al_init_timeout(&timeout, 0.8);
    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_display_event_source(display->getDisplay()));
}

// Core Functions
void Engine::engineQuit() {
    display->del();
}

void Engine::engineTick() {
    ALLEGRO_EVENT ev;
    while (1) {   
        if (!al_wait_for_event_until(queue, &ev, &timeout)) { break; }
        switch (ev.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                display->closed = true;
                setState(EQUIT);
                break;
            case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
                printf("Lost Focus\n");
                display->active = false;
                setState(EPAUSED);
                break;
            case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
                printf("Gained Focus\n");
                display->active = true;
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
    display->render();
}

void Engine::engineSleep() {
    if (state == EPAUSED) {
        return engineSleep(0.1); //Slower tick rate when the game is in the background
    }
    engineSleep(1/fps);
}

void Engine::engineSleep(float s) {
    al_rest(s);
}

// Modifiers
void Engine::setFps(int i) {
    fps = i;
}
int Engine::getFps() {
    return fps;
}

void Engine::setState(EngineState s) {
    state = s;
}

EngineState Engine::getState() {
    return state;
}

int Engine::addTickable(Tickable *t) {
    tickables.push_back(t);
    return tickables.size()-1; //Should be ID
}

bool Engine::rmvTickable(int id) {
    if (id >= tickables.size()) return false;
    tickables[id] = NULL;
    return true;
}

bool Engine::rmvTickable(Tickable *t) {
    return rmvTickable(t->id);
}