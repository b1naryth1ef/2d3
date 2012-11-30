#include "game.h"

Game::Game (Display *d) {
    display = d;
    fps = DEFAULT_FPS;
}

// Core Functions
void Game::gameQuit() {
    display->del();
}
void Game::gameTick() {
    if (display->getClosed()) {
        setState(QUIT);
    }
}
void Game::gameRender() {
    display->renderEvents();
    display->render();
}
void Game::gameSleep() {
    al_rest(1/fps);
}

// Modifiers
void Game::setFps(int i) {
    fps = i;
}
int Game::getFps() {
    return fps;
}

void Game::setState(GameState s) {
    state = s;
}

GameState Game::getState() {
    return state;
}