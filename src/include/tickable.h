#pragma once

#include "errors.h"

/*
    Tickables are a representation of something that needs to be constantly
    updated by the game engine. Tickables expect to have their .tick method
    called regularly (in our case, this should be every frame).
*/

class Tickable {
    public:
        bool active;

        // Default constructor, this probablly shouldn't be used anywhere
        Tickable (void) {
            active = true;
        }

        bool ticks () {
            if (active) {
                return this->tick();
            } else {
                return false;
            }
        };

        // Inheritors override this method
        virtual bool tick () {
            throw GenericEngineError(
                NOTIMPLEMENTTED,
                "Inheritors of Tickable must override and implement the .tick method!");

            return false;
        }
};
