/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
#include "perso.h"
#include "entity.h"

int main()
{
    SDL_Surface *screen,*backg;
    SDL_Event event;
    int loopgame=1;
    Player P;
    Entity E1;

    SDL_Init(SDL_INIT_VIDEO||SDL_INIT_AUDIO||SDL_INIT_TIMER);
    screen=SDL_SetVideoMode(1200,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);   

    init_Entity(&E1);
    init_perso(&P,screen);

backg=IMG_Load("/home/yassine/test ES/backg.jpg");

    SDL_EnableKeyRepeat(60,60);
    do
    {  
    	if (P.position.x<100)
        movment(&E1,P);
        else
        deplacerIA(&E1,P);
        
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    loopgame=0;
                break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                    case SDLK_d:
                        P.direction=1;
                        deplacer_perso(&P);
                        if(collisionBB(&E1,&P)!=0)
                        {
                            P.position.x=0;
                            P.position.y=400;
                        }
                        break;
                    
                    case SDLK_q:
                        P.direction=2;
                        deplacer_perso(&P);
                        if(collisionBB(&E1,&P)!=0)
                        {
                            P.position.x=0;
                            P.position.y=400;
                        }
                        break;

                    case SDLK_z:
                        P.direction=3;
                        deplacer_perso(&P);
                        if(collisionBB(&E1,&P)!=0)
                        {
                            P.position.x=0;
                            P.position.y=400;
                        }
                        break;

                    case SDLK_s:
                        P.direction=4;
                        deplacer_perso(&P);
                        if(collisionBB(&E1,&P)!=0)
                        {
                            P.position.x=0;
                            P.position.y=400;
                        }
                        break;
                    }
                break;
            }
        }
        annimation(&E1);
        afficher_ennemi(screen,E1,backg);
        afficher_perso(screen,P);
        SDL_Flip(screen);
    } while (loopgame!=0);
    
    SDL_FreeSurface(E1.Spritesheet);
    SDL_FreeSurface(screen);
    SDL_Quit();
    return 0;
}


//
