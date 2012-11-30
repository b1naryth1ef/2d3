#ifndef GAME_H
#define GAME_H

#include "global.h"
#include "display.h"

#define DEFAULT_FPS 60

enum GameState {LOADING, RUNNING, PAUSED, QUIT};

class Game {
    private:
        GameState state;
        int fps;
    public:
        // Public Vars
        Display *display;

        // Constructor
        Game (Display *d);

        // Core Functions
        void gameQuit();
        void gameTick();
        void gameRender();
        void gameSleep();

        // Modifiers
        void setFps(int i);
        int getFps();

        void setState(GameState s);
        GameState getState();
        
};

#endif