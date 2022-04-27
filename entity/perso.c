/**
* @file perso.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
#include"perso.h"

void init_perso(Player *hero, SDL_Surface *screen)
{
    hero->color=SDL_MapRGB(screen->format,0,255,0);

    hero->position.x=0;
    hero->position.y=400;
    hero->position.w=hero->position.h=64;

    hero->direction=0;
}
void afficher_perso(SDL_Surface *Screen,Player hero)
{
    SDL_FillRect(Screen,&hero.position,hero.color);
}
void deplacer_perso(Player *Hero)
{
    if(Hero->direction==1)
        Hero->position.x+=10;
    if(Hero->direction==2)
        Hero->position.x-=10;
    if(Hero->direction==3)
        Hero->position.y+=10;
    if(Hero->direction==4)
        Hero->position.y-=10;
    
}
