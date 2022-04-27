/**
* @file enigme.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for enigme image
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "enigme.h"
/**
* @brief to give a random int  .
* @param nomfichier le nom de fichier
* @return Nothing
*/
int random_enigme(char *nomfichier)
{
    srand(time(NULL));
    return (rand() % 4);
}

void initEnigme(enigme *e, char *nomfichier)
{   
    e->num_question = random_enigme(nomfichier);

    

    e->won= IMG_Load("/home/mokhtar/Desktop/tache_enigme/enigme_mokhtar/mokhtar2/resenigme/You-win.png");
    e->lost= IMG_Load("/home/mokhtar/Desktop/tache_enigme/enigme_mokhtar/mokhtar2/resenigme/wrong.png");
    char path[150];
    int numquestion;
    e->rep_joueur = -1;
	FILE *f = NULL;
    f = fopen(nomfichier, "r");
    if (f != NULL)
    {
        do
        {
            fscanf(f, "%d %s %d\n", &numquestion, path, &e->rep_vrai);
        } while ((numquestion != e->num_question) && (f != feof));
    }
    fclose(f);
 e->background = IMG_Load(path);

    e->pos_back.x = 0;
    e->pos_back.y = 0;

    e->pos_wonlose.x = 0;
    e->pos_wonlose.y = 0;

    e->pos_clock.x=0;
    e->pos_clock.y=0;
    e->frame=1;
    e->clock=IMG_Load("resenigme/Clock1.png");
    e->lastTime=0;

}
void afficherEnigme(enigme *e, SDL_Surface *s)
{
    SDL_BlitSurface(e->background, NULL, s, &e->pos_back);
    SDL_BlitSurface(e->clock,NULL,s,&e->pos_clock);
}

void animer (enigme *e){
	e->currentTime = SDL_GetTicks();
	if (e->currentTime > e->lastTime +1000) {
		char path[50];
		sprintf(path,"resenigme/Clock%d.png",e->frame);
		e->clock=IMG_Load(path);
		//printf("%s\n",path);
		e->frame++;
		if(e->frame==5){
		e->frame=1;}		
    		e->lastTime = e->currentTime;
  	}

}

