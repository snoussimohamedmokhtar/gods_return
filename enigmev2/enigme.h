#ifndef ENIGME_H
#define ENIGME_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{	

	SDL_Surface *background;
	SDL_Rect pos_backbackground;
	
	SDL_Surface *question;
	SDL_Rect pos_question;
	
	SDL_Surface *reponses[3];
	SDL_Surface *reponsesvert[3];
	
	
	
	SDL_Rect pos_reponse1;
	SDL_Rect pos_reponse2;
	SDL_Rect pos_reponse3;
	
	int rep_joueur;
	int reponse_vrai;

	int ligne_question;
	
	SDL_Surface *picAnim;
	int frame;
	int lastTime;
	int currentTime;
	
}enigme;



void afficherEnigmetext(enigme *e, SDL_Surface *s,int b);

//image
typedef struct
{
    SDL_Rect src;
    SDL_Rect dist;
    SDL_Surface *img;
}image;

SDL_Surface *LoadIMG(char nom[20]);
void INIT_IMGB(image *I,char nom[20]);
void displayIMG(image I,SDL_Surface *ecran);


//enigme
void initEnigme(enigme *e , char *nomfichier);
void afficherEnigme(enigme *e, SDL_Surface * s);
void animer (enigme *e);



#endif 
