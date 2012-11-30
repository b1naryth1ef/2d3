#include "engine.h"

// Constructor
Engine::Engine (Display *d) {
    display = d;
    fps = DEFAULT_FPS;
    al_init_timeout(&timeout, 0.06);
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
        if (!al_wait_for_event_until(queue, &ev, &timeout)) {
            break;
        }
        switch (ev.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                printf("Closed display!\n");
                display->closed = true;
                setState(EQUIT);
                break;
            case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
                printf("Out\n");
                display->active = false;
                setState(ERUNNING);
                break;
            case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
                printf("In\n");
                display->active = true;
                setState(EPAUSED);
                break;
        }
    }
}

void Engine::engineRender() {
    display->renderEvents();
    display->render();
}

void Engine::engineSleep() {
    al_rest(1/fps);
}

void Engine::engineSleep(int s) {
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