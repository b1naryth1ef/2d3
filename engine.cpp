#include "engine.h"

EngineState estate = ELOADING;

void setEngineState (EngineState s) {
    estate = s;
}

EngineState getEngineState () {
    return estate;
}

// Constructor
Engine::Engine () {
    fps = DEFAULT_FPS;
}

// Core Functions
void Engine::addFunc(void (*pointer)(int, bool)) {
    inputables.push_back(pointer);
}

void Engine::setDisplay (Display *d) {
    display = d;
}

void Engine::init () {
    al_init();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    al_install_mouse();

    timer = al_create_timer(1.0 / DEFAULT_FPS);
    display = new Display (size_x, size_y);
    tqueue = al_create_event_queue();
    iqueue = al_create_event_queue();
    al_register_event_source(tqueue, al_get_timer_event_source(timer));
    al_register_event_source(iqueue, al_get_mouse_event_source());
    al_register_event_source(iqueue, al_get_keyboard_event_source());
}

void Engine::engineQuit() {
    display->del();
    al_destroy_timer(timer);
}

void Engine::tickInput () {
    ALLEGRO_EVENT ev;
    while (!al_is_event_queue_empty(iqueue)) {
        al_get_next_event(iqueue, &ev);
        if (ev.type == ALLEGRO_EVENT_KEY_UP || ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            bool g = ev.type == ALLEGRO_EVENT_KEY_UP;
            for (int i=0; i < inputables.size(); i++) {
                inputables[i](ev.keyboard.keycode, g);
            }
        }
    }
}

void Engine::engineStart() {
    al_start_timer(timer);
    ALLEGRO_EVENT ev;
    while (1) {   
        al_wait_for_event(tqueue, &ev);

        // Tick other queues
        tickInput();
        display->tick(); //This just grabs events, doesnt render

        // Change engine states depending on display status
        if (display->getDisplayState() == DCLOSED) { setEngineState(EQUIT); }
        else if (display->getDisplayState() == DINACTIVE) { setEngineState(EPAUSED);}
        else if (getEngineState() != ERUNNING) { setEngineState(ERUNNING); }

        // Engine actions depending on state
        if (getEngineState() == EPAUSED) { continue; }
        else if (getEngineState() == EQUIT) { return engineQuit(); }

        // Tick all our tickables
        for (int i=0; i < tickables.size(); i++) {
            tickables[i]->ticks();
        }

        engineRender();
    }
}

void Engine::engineRender() {
    if (getEngineState() == EPAUSED) {return;}
    display->renderEvents();
    display->render();
}

void Engine::engineSleep() {
    if (getEngineState() == EPAUSED) {
        return engineSleep(0.1); //Slower tick rate when the game is in the background
    }
    engineSleep(1/fps);
}

void Engine::engineSleep(float s) { al_rest(s); }

// Modifiers
void Engine::setFps(int i) { fps = i; }
int Engine::getFps() { return fps; }

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