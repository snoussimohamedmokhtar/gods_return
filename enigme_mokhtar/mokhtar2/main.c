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
#include <stdio.h>
#include "SDL/SDL.h"
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"
#include <time.h>
int main()
{
    SDL_Surface *ecran = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;
    ecran = SDL_SetVideoMode(1600, 900, 32, SDL_HWSURFACE);
    int continuer = 1;
    enigme eng;
    char nomfichier[200] = "/home/mokhtar/Desktop/tache_enigme/enigme_mokhtar/mokhtar2/resenigme/enigmefile";
    
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
     Mix_Chunk * son;
     son= Mix_LoadWAV("/home/mokhtar/Desktop/tache_enigme/enigme_mokhtar/mokhtar2/resenigme/Jackpot Sound Effect HD.wav");
     Mix_Chunk * son1;
     son1= Mix_LoadWAV("/home/mokhtar/Desktop/tache_enigme/enigme_mokhtar/mokhtar2/resenigme/Buzzer Wrong Answer - Gaming Sound Effect (HD).wav");

    initEnigme(&eng, nomfichier);
    
    while (continuer)
    {
	animer(&eng);
        afficherEnigme(&eng, ecran);
      
         SDL_PollEvent(&event);
          SDL_GetMouseState(&(eng.x), &(eng.y));
         switch (event.type)
    {
    case SDL_QUIT:
        continuer = 0;
            break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_a:
           eng.rep_joueur = 1;
            break;
        case SDLK_b:
           eng.rep_joueur = 2;
            break;
        case SDLK_c:
           eng.rep_joueur = 3;
            break;
        }
    case SDL_MOUSEBUTTONUP:
	
	if(event.motion.x>=131 && event.motion.x<=131+148 && event.motion.y>=278 && event.motion.y<=278+147)
	{
	   eng.rep_joueur = 1;
	}

        else if(event.motion.x>=131 && event.motion.x<=133+152 && event.motion.y>=460 && event.motion.y<=460+152)
	{
	   eng.rep_joueur = 2;
	}
	
        else if(event.motion.x>=131 && event.motion.x<=133+156 && event.motion.y>=655 && event.motion.y<=655+144)
	{
	   eng.rep_joueur = 3;
	}
	
	//cas enigme 4
	if(event.motion.x>=194 && event.motion.x<=194+65 && event.motion.y>=43 && event.motion.y<=43+37)
	{
	   eng.rep_joueur = 1;
	}

        else if(event.motion.x>=236 && event.motion.x<=236+51 && event.motion.y>=85 && event.motion.y<=85+72)
	{
	   eng.rep_joueur = 2;
	}
	
        else if(event.motion.x>=343 && event.motion.x<=343+54 && event.motion.y>=86 && event.motion.y<=86+71)
	{
	   eng.rep_joueur = 3;
	}

        break;
    }
    
      if (eng.rep_joueur != -1)
     {
        if (eng.rep_joueur == eng.rep_vrai)
        {
            SDL_BlitSurface(eng.won, NULL, ecran, &eng.pos_wonlose);
	    Mix_PlayChannel(-1, son, 0);
            eng.score_enigme = 1;
        }
        else if(eng.rep_joueur != eng.rep_vrai)
        {
            SDL_BlitSurface(eng.lost, NULL, ecran, &eng.pos_wonlose);
	    Mix_PlayChannel(-1, son1, 0);
            eng.score_enigme = 0;
        }
     }
   
 
        SDL_Flip(ecran);
        if ((eng.rep_joueur != -1))
        {
            SDL_Delay(5000);
            continuer = 0;
        }
    }
    Mix_FreeChunk(son);
    Mix_FreeChunk(son1);
}
