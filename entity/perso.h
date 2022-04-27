#ifndef PERSO_H
#define PERSO_H
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
/**
* @struct Player
* @brief struct for player
*/
typedef struct
{
    SDL_Rect position;
    Uint32 color;
    int direction;
}Player;

void init_perso(Player *hero,SDL_Surface *screen);
void afficher_perso(SDL_Surface *Screen,Player hero);
void deplacer_perso(Player *Hero);

#endif
