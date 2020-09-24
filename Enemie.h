#ifndef ENEMIE_H_INCLUDED
#define ENEMIE_H_INCLUDED
#include "sprite.h"
#include "Point.h"
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <fstream>
#include <sstream>
using namespace std;

class Enemie:public Sprite{
public:
    Point *p1[3];
   // Point *p2;
   // Point *p3;
   int enemy_point;
    Enemie(SpriteSheet *sheet, int width = 32, int height = 32);
    void looking_for_point(Point *pp1,Point *pp2,Point *pp3){
        //implement looking for point by enemie.
        p1[0]=pp1;
        p1[1]=pp2;
        p1[2]=pp3;
    }
    void draw(SDL_Renderer * renderer);
    void move();
    void move(int dx,int dy);
    void search_item();
    void enemy_got_point();
    void drawScore(SDL_Renderer* renderer);
};


#endif // ENEMIE_H_INCLUDED
