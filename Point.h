#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include "sprite.h"
#include "player.h"

#include <math.h>
#include <time.h>
using namespace std;

class Point:public Sprite{
private:
    static int scoreReached;
    bool ate;
public:
    Point(SpriteSheet *sheet,int w=32,int h=32);
    void draw(SDL_Renderer * renderer);
    void move();
    void move(int dx,int dy);
    int catched(Player *plajer);
    int generate_random(int n);
    void random_position(Point *p1);

};


#endif // POINT_H_INCLUDED
