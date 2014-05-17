#pragma once

class Tickable {
    private:
        bool active;
    public:
        int id;
        Tickable (void);
        bool ticks ();
        virtual bool tick ();
        bool getActive();
        void setActive(bool v);
};
