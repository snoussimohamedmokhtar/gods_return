#ifndef TEXTE_H
#define TEXTE_H
#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
typedef struct
{
	SDL_Rect pos;
	TTF_Font *font;
	SDL_Surface *surtext;
	SDL_Color TColor;
	char text[50];
}texte;

TTF_Font *INIT_FONT(char nom[20]);
void INIT_texte(texte *T,char nom[20]);
void displayText(texte t,SDL_Surface *screen);


#endif
