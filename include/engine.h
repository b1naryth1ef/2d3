#pragma once

#include "global.h"
#include "display.h"
#include "tickable.h"
#include "sprite.h"
#include "entity.h"
#include <vector>
#include <map>

#define DEFAULT_FPS 60

enum EngineState {ELOADING, ERUNNING, EPAUSED, EQUIT};

void setEngineState(EngineState s); 
EngineState getEngineState(); 
typedef void (*fpointer)(int, bool);
typedef void (*callpoint)();

class Engine {
    private:
        std::vector<Tickable *> tickables;
        ALLEGRO_EVENT_QUEUE *tqueue; //Tick queue
        ALLEGRO_EVENT_QUEUE *iqueue; //Input queue
        ALLEGRO_FONT *font;
        ALLEGRO_TIMER *timer;
        cpSpace *space;
        int fps;

        // Hooks
        callpoint callOnTick;
        callpoint callPreRender;
        callpoint callPostRender;
        

        void tickInput();

    public:
        // Public Vars
        Display *display;
        InputHolder input;

        // Constructor
        Engine ();

        // Core Functions
        void init();
        void engineQuit();
        void engineStart();
        void engineRender();
        void engineSleep();
        void engineSleep(float s);

        // Entities
        void addEntity(Entity *s);
        void rmvEntity(Entity *s);

        // Tickables
        int findTickable(Tickable *t);
        void addTickable(Tickable *t);
        void rmvTickable(Tickable *t);

        // Modifiers
        void setDisplay(Display *d);
        void setFps(int i);
        int getFps();

        // Calls
        void setCallOnTick(callpoint f) { callOnTick = f; }
        void setCallPreRender(callpoint f) { callPreRender = f; }
        void setCallPostRender(callpoint f) { callPostRender = f; }
};
