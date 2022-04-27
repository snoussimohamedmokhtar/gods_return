#ifndef ENTITY_H
#define ENTIT_H
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
#include "perso.h"
/**
* @struct Entity
* @brief struct for entity
*/
typedef struct
{
    SDL_Surface *Spritesheet;
    SDL_Rect animation,position;
    int direction;
    float timeFrame,curentTime,PrevTime,deltaT;
}Entity;

void init_Entity(Entity *ennemi);
void afficher_ennemi(SDL_Surface *Screen, Entity ennemi,SDL_Surface *backg);
int collisionBB(Entity *ennemi, Player *hero);
void movment(Entity *ennemie,Player p);
void annimation( Entity *ennemi);
void deplacerIA(Entity *e,Player p);
#endif 
