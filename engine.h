#ifndef ENGINE_H
#define ENGINE_H

#include "global.h"
#include "display.h"
#include "tickable.h"
#include "sprite.h"
#include <vector>

#define DEFAULT_FPS 60

enum EngineState {ELOADING, ERUNNING, EPAUSED, EQUIT};

class Engine {
    private:
        EngineState state;
        std::vector<Tickable *> tickables;
        ALLEGRO_EVENT_QUEUE *queue;
        ALLEGRO_TIMEOUT timeout;
        ALLEGRO_FONT *font;
        ALLEGRO_TIMER *timer;
        int fps;

    public:
        // Public Vars
        Display *display;

        // Constructor
        Engine ();
        //Engine (Display *d);

        // Core Functions
        void init();
        void engineQuit();
        void engineStart();
        void engineRender();
        void engineSleep();
        void engineSleep(float s);

        // Sprites
        void addSprite(BaseSprite *s);
        void rmvSprite(BaseSprite *s);

        // Tickables
        int findTickable(Tickable *t);
        void addTickable(Tickable *t);
        void rmvTickable(Tickable *t);

        // Modifiers
        void setDisplay(Display *d);
        void setFps(int i);
        int getFps();

        void setState(EngineState s);
        EngineState getState();
        
};

#endif