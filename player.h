#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL2/SDL.h>

#include "drawable.h"
#include "movable.h"
#include "keyboardeventlistener.h"
#include "sprite.h"

class Player : public Drawable, public Movable, public KeyboardEventListener {
public:
    Sprite *sprite;

public:
    Player(Sprite *sprite);
    virtual void draw(SDL_Renderer *renderer);
    virtual void move();
    virtual void move(int dx, int dy);
    virtual void listen(SDL_KeyboardEvent &event);

};

#endif // PLAYER_H_INCLUDED
