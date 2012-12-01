#ifndef ENGINE_H
#define ENGINE_H

#include "global.h"
#include "display.h"
#include "tickable.h"
#include <vector>

#define DEFAULT_FPS 60

enum EngineState {ELOADING, ERUNNING, EPAUSED, EQUIT};

class Engine {
    private:
        EngineState state;
        std::vector<Tickable *> tickables;
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
        void engineSleep(float s);

        // Tickables
        int addTickable(Tickable *t);
        bool rmvTickable(int id);
        bool rmvTickable(Tickable *t);

        // Modifiers
        void setFps(int i);
        int getFps();

        void setState(EngineState s);
        EngineState getState();
        
};

#endif