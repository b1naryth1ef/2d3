#ifndef TICKABLE_H
#define TICKABLE_H

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


#endif