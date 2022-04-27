#ifndef PERSO_H
#define PERSO_H
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
