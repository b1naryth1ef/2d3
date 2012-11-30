#include "sprite.h"

BaseSprite::BaseSprite (ALLEGRO_BITMAP *bmp) {
    img = bmp;
    x = 0.1;
    y = 0.1;
}

bool BaseSprite::renders(ALLEGRO_DISPLAY *display) {
    al_draw_bitmap(img, x, y, 0);
    return true;
}

bool BaseSprite::tick() {
    x += .1;
    y += .1;
    return true;
}
