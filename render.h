#ifndef RENDER_H
#define RENDER_H

#include "global.h"

int addGlobalImage ();
void rmvGlobalImage ();

enum TextType {LEFT, CENTER, RIGHT};

class Renderable {
    private:
        bool active;
        char name;
    public:
        Pos *pos;
        // Constructor
        Renderable ();

        bool isActive ();
        void setActive (bool i);
        void setPos (Pos *p);
        // Overwriteables
        virtual bool renders (ALLEGRO_DISPLAY *display);
};

class Text : public Renderable {
    private:
        const char *text;
        ALLEGRO_FONT *font;
        ALLEGRO_COLOR color;
        TextType align;
    public:
        // Constructor
        Text (const char *t, ALLEGRO_FONT *f);
        Text (const char *t, ALLEGRO_FONT *f, ALLEGRO_COLOR *c);

        // Overwrites
        bool renders (ALLEGRO_DISPLAY *display);

        // Setters
        void setTextType(TextType t);
        void setText(char *t);
        void setColor(ALLEGRO_COLOR *c);
        void setFont(ALLEGRO_FONT *f);

        // Getters
        ALLEGRO_COLOR *getColor();
        ALLEGRO_FONT *getFont();
        const char *getText();
        TextType getTextType();
};
#endif