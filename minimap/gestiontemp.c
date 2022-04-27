#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <time.h>
#include "gestiontemp.h"

void inittemps(temps *t)
{
    t->tempsActuel=0;
    t->tempsPrecedent=0;
    t->compteur=0;
    t->texte=NULL;
    t->positionTemps.x=10;
    t->positionTemps.y=10;
    t->police =TTF_OpenFont("police.ttf",50) ;
	
}

void updatetemps(temps *t)
{
    t->tempsActuel=SDL_GetTicks();
    if((t->tempsActuel)- (t->tempsPrecedent)>=1000)
    {
        t->compteur+=1;
        t->tempsPrecedent=t->tempsActuel;
    }

}


void affichage_temps(temps *t,char temps[])
{
    int mm=0,ss=0;
    SDL_Color couleurblanche = {255, 255, 255};
    mm=(t->compteur)/60;
    ss=(t->compteur)-mm*60;
    sprintf(temps,"temps : %d:%d",mm,ss);
    t->texte =TTF_RenderText_Solid(t->police,temps,couleurblanche);
}

void blitTemps(temps *t,SDL_Surface *ecran)
{
    SDL_BlitSurface(t->texte,NULL,ecran,&(t->positionTemps));
}


void free_temps(temps *t)
{
    SDL_FreeSurface(t->texte);
    TTF_CloseFont(t->police);
}


// ########################## score 



void initscore(score *s)
{
    s->scorecount=0;;
    s->score=NULL;
    s->positionscore.x=10;
    s->positionscore.y=60;
    s->police =TTF_OpenFont("police.ttf",50) ;
}

void updatescore(score *s)
{
        s->scorecount=300;
}


void affichage_score(score *s,char score[])
{
    SDL_Color couleurblanche = {255, 255, 255};
    sprintf(score,"score : %d",s->scorecount);
    SDL_FreeSurface(s->score);
    s->score =TTF_RenderText_Solid(s->police,score,couleurblanche);
}

void blitscore(score *s,SDL_Surface *ecran)
{
    SDL_BlitSurface(s->score,NULL,ecran,&s->positionscore);
}


void free_score(score *s)
{
    SDL_FreeSurface(s->score);
    TTF_CloseFont(s->police);
}





