#ifndef ASMA_H
#define ASMA_H

#include<SDL/SDL.h>
#include<SDL/SDL_asma.h>

typedef struct
{
    SDL_Rect src;
    SDL_Rect dist;
    SDL_Surface *img;
}background;

void initBack(Background * b);
void aficherBack(Background b, SDL_Surface * screen);
void animerBackground( Background * e);
int collisionPP( Personne p, SDL_Surface * Masque);
void scrolling (background * b, int direction, int pasAvancement);
void scrolling (SDL_Rect * b, int direction ,int pasAvancement);


#endif //ASMA_H
