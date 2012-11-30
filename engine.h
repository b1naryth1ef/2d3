#ifndef ENGINE_H
#define ENGINE_H

#include "global.h"
#include "display.h"

#define DEFAULT_FPS 60

enum EngineState {ELOADING, ERUNNING, EPAUSED, EQUIT};

class Engine {
    private:
        EngineState state;
        ALLEGRO_EVENT_QUEUE *queue;
        ALLEGRO_TIMEOUT timeout;
        int fps;

    public:
        // Public Vars
        Display *display;

        // Constructor
        Engine (Display *d);

        // Core Functions
        void engineQuit();
        void engineTick();
        void engineRender();
        void engineSleep();
        void engineSleep(int s);

        // Modifiers
        void setFps(int i);
        int getFps();

        void setState(EngineState s);
        EngineState getState();
        
};

#endif