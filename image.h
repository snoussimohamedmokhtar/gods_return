#ifndef IMAGE_H
#define IMAGE_H

#include<SDL/SDL.h>
#include<SDL/SDL_image.h>

typedef struct
{
    SDL_Rect src;
    SDL_Rect dist;
    SDL_Surface *img;
}image;

SDL_Surface *LoadIMG(char nom[20]);
void INIT_IMGB(image *I,char nom[20]);
void INIT_play(image *I,char nom[20]);
void displayIMG(image I,SDL_Surface *screen);
int MouseTest(SDL_Event event ,image P);
void clean(SDL_Surface *S);


#endif //IMAGE_H
