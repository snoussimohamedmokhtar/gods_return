#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <math.h>
#include <time.h>
#include "string.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



struct background
{
	SDL_Surface* bg;
	SDL_Rect pos_bg;
	SDL_Rect pos_scrolling;
	int end_scrolling_right,end_scrolling_left;
};
typedef struct background background; 




struct minimap
{
	SDL_Surface* mini_map;
	SDL_Rect pos_minimap;
	SDL_Surface* mini_hero;
	SDL_Rect pos_minihero;
	
	
};
typedef struct minimap minimap; 


void init_background (background* bg);
void scrolling_right (background* bg );
void scrolling_left (background* bg);
void free_background (background* bg);
void blit_background (background* bg,SDL_Surface* screen);


void init_minimap(minimap* mp);
void blit_minimap( minimap* mp,SDL_Surface *screen);
void dep_mini_hero (SDL_Rect* pos_perso,minimap *mp , SDL_Rect camera,int redimensionnement,int sens,float size);
void free_minimap(minimap* mp);

void singleplayer( SDL_Surface *screen );



void init_background_bottom (background* bg);
//void scrolling_right_bottom (background* bg , int* test_scrolling_end_right);
//void scrolling_left_bottom (background* bg, int* test_scrolling_end_left);
void free_background_bottom (background* bg);
void blit_background_bottom (background* bg,SDL_Surface* screen);


void init_minimap_bottom(minimap* mp);
void blit_minimap_bottom( minimap* mp,SDL_Surface *screen);
void dep_mini_hero_bottom (SDL_Rect* pos_perso,minimap *mp , SDL_Rect camera,int redimensionnement,int sens);
void free_minimap_bottom(minimap* mp);

void multiplayer ( SDL_Surface *screen );

#endif 
