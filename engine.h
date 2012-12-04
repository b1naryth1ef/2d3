#ifndef ENGINE_H
#define ENGINE_H

#include "global.h"
#include "display.h"
#include "tickable.h"
#include "sprite.h"
#include <vector>
#include <map>

#define DEFAULT_FPS 60

enum EngineState {ELOADING, ERUNNING, EPAUSED, EQUIT};
//extern EngineState estate;

void setEngineState(EngineState s); 
EngineState getEngineState(); 
typedef void (*fpointer)(int, bool);

class Engine {
    private:
        std::vector<Tickable *> tickables;
        std::vector<fpointer> inputables;
        ALLEGRO_EVENT_QUEUE *tqueue; //Tick queue
        ALLEGRO_EVENT_QUEUE *iqueue; //Input queue
        ALLEGRO_FONT *font;
        ALLEGRO_TIMER *timer;
        int fps;

        void tickInput();

    public:
        // Public Vars
        Display *display;

        // Constructor
        Engine ();

        // Core Functions
        void init();
        void engineQuit();
        void engineStart();
        void engineRender();
        void engineSleep();
        void engineSleep(float s);

        // Input
        void addFunc(void (*pointer)(int, bool));

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

        
        
};

#endif