#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"
#include <string.h>
#include "SDL_rotozoom.h"

int main(int argc,char **argv)
{
    SDL_Surface *screen =NULL,*chose = NULL;
    SDL_Rect pos_chose;
    SDL_Init(SDL_INIT_EVERYTHING);

    chose = IMG_Load("chose.png");
    pos_chose.x = 0;
    pos_chose.y = 0;


    SDL_Event event;
    screen=SDL_SetVideoMode(800,600, 32,SDL_HWSURFACE| SDL_DOUBLEBUF);
    SDL_WM_SetCaption("game",NULL);

    int continuer=1;
    while(continuer == 1)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;

            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE://pour quitter
                continuer=0;

                break;

            case SDLK_RIGHT :
            {
		singleplayer(screen); 
            }
            break;
	    
            case SDLK_LEFT :
            {
		multiplayer(screen); 

    		screen=SDL_SetVideoMode(800,600, 32,SDL_HWSURFACE| SDL_DOUBLEBUF);            }
            break;

            }
            break;

case SDL_MOUSEBUTTONDOWN:
        {
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:
            {
                if ( event.button.x>20 && event.button.x<230 && event.button.y>255 && event.button.y<345) 
                {
                    singleplayer(screen); 
                }
                
                if ( event.button.x>570 && event.button.x<780 && event.button.y>255 && event.button.y<345) 
                {
                   multiplayer(screen); 
    screen=SDL_SetVideoMode(800,600, 32,SDL_HWSURFACE| SDL_DOUBLEBUF);
                }
            }
            break; 
            }
        }
        break;



        }// taskiret les events mtaa les boutons
        SDL_BlitSurface(chose,NULL,screen,&pos_chose);
	SDL_Flip(screen);
	SDL_Delay(100);

    } // taskiret continuer
    SDL_FreeSurface(chose);
    SDL_Quit();

    return EXIT_SUCCESS ;
}

