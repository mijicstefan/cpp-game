#include "Point.h"

int Point::scoreReached=0;

Point::Point(SpriteSheet *sheet, int width, int height):Sprite(sheet,width,height){
    ate=false;
    spriteRect->x=generate_random(10)*32;
    spriteRect->y=generate_random(20)*32;
}

void Point::draw(SDL_Renderer * renderer){
    sheet->drawFrame("walk_down",0,spriteRect,renderer);
}

void Point::move(){}
void Point::move(int dx,int dy){}

int Point::catched(Player *plajer){
    int x1=plajer->sprite->spriteRect->x;
    int x2=spriteRect->x-32;

    int y1=plajer->sprite->spriteRect->y;
    int y2=spriteRect->y-32;


    if(abs(x1-x2)<32 && abs(y1-y2)<32){
        int x_r=generate_random(10)*32;
        int y_r=generate_random(20)*32;
        int x_b= spriteRect->x;
        int y_b=spriteRect->y;
        spriteRect->x=x_r;
        spriteRect->y=y_r;

        if(x_b==spriteRect->x && y_b==spriteRect->y){
            return scoreReached;
        }
            scoreReached++;
    }
    return scoreReached;

}

void Point::random_position(Point *p2){
    int i=0;
   while(abs(spriteRect->x-p2->spriteRect->x)<64 && abs(spriteRect->y - p2->spriteRect->y)<64 ){

        spriteRect->x=p2->spriteRect->x+generate_random(10)*32;
        spriteRect->y=p2->spriteRect->y+generate_random(20)*32;
        if (spriteRect->x < 0){
            spriteRect->x = 0;
        }else if (spriteRect->x > 32*9){
            spriteRect->x = 32*9;
        }
        if ( spriteRect->y < 0){
            spriteRect->y =0;
        }else if (spriteRect->y >32*19){
            spriteRect->y = 32*19;
        }
        i++;
        if(i==500){
            break;
        }
    }
}
int Point::generate_random(int n){
    srand(time(0));
    return rand()%n;
}

