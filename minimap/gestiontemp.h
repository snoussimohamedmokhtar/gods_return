#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <time.h> 

struct temps
{
    int tempsActuel;
    int tempsPrecedent;
    int compteur;
    SDL_Surface *texte;
    SDL_Rect positionTemps;
    TTF_Font *police;
};
typedef struct temps temps;


struct score
{
    int scorecount;
    SDL_Surface *score;
    SDL_Rect positionscore;
    TTF_Font *police;

};
typedef struct score score;

void inittemps(temps *t);
void updatetemps(temps *t);
void affichage_temps(temps *t,char temps[]);
void blitTemps(temps *t,SDL_Surface *ecran);
void free_temps(temps *t);


void initscore(score *s);
void updatescore(score *s);
void affichage_score(score *s,char score[]);
void blitscore(score *s,SDL_Surface *ecran);
void free_score(score *s);
