#ifndef DISPLAY_H
#define DISPLAY_H

#include "global.h"
#include "render.h"
#include <vector> 
#include <map>

#define DEFAULT_TITLE "2D3 -- Test Engine"

static std::map<int, ALLEGRO_FONT*> FONTS;

bool loadFont (int f, const char * name, int size);
bool unloadFont (int f);
ALLEGRO_FONT *getFont (int f);

class Display {
    private:
        void Init (int w, int h);
        ALLEGRO_DISPLAY *display;
        ALLEGRO_COLOR bgcolor;
        int size_w, size_h;   
        bool closed, active;  
        char title [50];
        std::vector<Renderable *> renderables;

    public:
        
        Display (int w, int h);
        Display (int w, int h, ALLEGRO_COLOR c);

        ALLEGRO_DISPLAY* getDisplay();

        // Getters
        char *getTitle();
        bool getClosed ();
        bool getActive ();
        int getWidth();
        int getHeight();

        // Setters
        void setClosed (bool v);
        void setActive (bool v);
        void setTitle(char t[50]);
        void setBackgroundColor(ALLEGRO_COLOR c);

        // Calls
        void del ();
        void render();
        void renderEvents();

        // Renderables
        int findRenderable(Renderable *r);
        void addRenderable(Renderable *r);
        void rmvRenderable(Renderable *r);
};

#endif