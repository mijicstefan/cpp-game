#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "drawable.h"
#include "movable.h"

#include "spritesheet.h"

using namespace std;

class Sprite : public Drawable, public Movable {
public:
    enum State:short int {STOP=0, LEFT=1, RIGHT=2, UP=4, DOWN=8,
                     LEFT_UP=LEFT|UP, LEFT_DOWN=LEFT|DOWN,
                     RIGHT_UP=RIGHT|UP, RIGHT_DOWN=RIGHT|DOWN};
protected:
    int currentFrame;
    int frameCounter;
    int frameSkip;
    int speed;
    short int state;
public:
    SpriteSheet *sheet;
    SDL_Rect *spriteRect;
    Sprite(SpriteSheet *sheet, int width=64, int height=64);
    int getFrameSkip();
    void setFrameSkip(int frameSkip);
    short int getState();
    void setState(short int state);
    virtual void draw(SDL_Renderer *renderer);
    void set_speed(int speed1){speed=speed1;}
    virtual void move();
    virtual void move(int dx, int dy);

};

#endif // SPRITE_H_INCLUDED
