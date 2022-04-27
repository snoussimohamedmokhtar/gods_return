#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include<stdio.h>
#include<stdlib.h>
#include"image.h"
#include"texte.h"

int main(int argc , char *argv[])
{
    //declaration enigme :
    //enigme eng;
    //char nomfichier[200] = "/home/mokhtar/Desktop/tache_enigme/enigme_mokhtar/mokhtar2/resenigme/enigmefile";



    
    SDL_Surface *screen;
    SDL_Event event;
    image I[15];
    texte T;
    int i;
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)!=0)
    {
        printf("error init \n");
    }
    //texte : 
    TTF_Init();
    INIT_texte(&T,"arial.ttf");
    //sound :
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
      Mix_Music *m;
      m=Mix_LoadMUS("/home/mokhtar/jeu_tab/music_c.mp3");
      Mix_PlayMusic(m,-1);
      Mix_Chunk * son;
      son= Mix_LoadWAV( "/home/mokhtar/jeu_tab/sonbref.wav");


    INIT_IMGB(&I[0],"/home/mokhtar/Desktop/projet_final/menu.png");
    INIT_IMGB(&I[1],"/home/mokhtar/Desktop/projet_final/play_on(1).png");
    INIT_IMGB(&I[2],"/home/mokhtar/Desktop/projet_final/settings_on(1).png");
    INIT_IMGB(&I[3],"/home/mokhtar/Desktop/projet_final/exit_on(1).png");
    INIT_IMGB(&I[4],"/home/mokhtar/Desktop/projet_final/settings_menu_mini_.png");
    INIT_IMGB(&I[5],"/home/mokhtar/jeu_tab/1_.png");
    INIT_IMGB(&I[6],"/home/mokhtar/jeu_tab/2_.png");
    INIT_IMGB(&I[7],"/home/mokhtar/jeu_tab/3_.png");
    INIT_IMGB(&I[8],"/home/mokhtar/Desktop/projet_final/choose your fighter.png");
    INIT_IMGB(&I[9],"/home/mokhtar/Desktop/projet_final/volume_p.png");
    INIT_IMGB(&I[10],"/home/mokhtar/Desktop/projet_final/character 1 (after mouse motion).png");
    INIT_IMGB(&I[11],"/home/mokhtar/Desktop/projet_final/character 2 (after mouse motion).png");
    INIT_IMGB(&I[12],"/home/mokhtar/Desktop/projet_final/continue (after mouse motion).png");

	//*****************init enigme********************
	//initEnigme(&eng, nomfichier);

    screen=SDL_SetVideoMode(1600,900,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    int loop=1;
    while (loop==1)
    {
        displayIMG(I[0],screen);
        displayText(T,screen);
        SDL_PollEvent(&event);

            switch(event.type)
            {
                case SDL_QUIT:
                    loop=0;
                    break;
	
		case SDL_KEYUP:
                   
		    	if(event.key.keysym.sym ==SDLK_s)
			{
			    while(event.key.keysym.sym !=SDLK_ESCAPE)
			    {
				   displayIMG(I[4],screen);
				   displayIMG(I[9],screen);
				   SDL_Flip(screen);
				   SDL_PollEvent(&event);
				switch(event.type)
				{
					case SDL_KEYDOWN:
				   if(event.key.keysym.sym==SDLK_w)
				   {
					Mix_VolumeMusic(MIX_MAX_VOLUME/8);
					if(I[9].dist.x>0)
					{I[9].dist.x = 0;}
					else if(I[9].dist.x>-100)
					{I[9].dist.x = I[9].dist.x - 100;}

					
				   }
				   if(event.key.keysym.sym==SDLK_v)
				   {
					Mix_VolumeMusic(MIX_MAX_VOLUME);
					if(I[9].dist.x<0)
					{I[9].dist.x = 0;}
					else if(I[9].dist.x<100)
					{I[9].dist.x = I[9].dist.x + 100;}

					
				   }
				   if(event.key.keysym.sym==SDLK_f)
				   {
					screen=SDL_SetVideoMode(1900,1200,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
				   }
				   if(event.key.keysym.sym==SDLK_m)
				   {
					screen=SDL_SetVideoMode(1600,900,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
				   }
					break;
				}
                            }
			}
			if(event.key.keysym.sym ==SDLK_p)
			{
				while(event.key.keysym.sym !=SDLK_ESCAPE)
				{
				   displayIMG(I[8],screen);
				   SDL_Flip(screen);
				   SDL_PollEvent(&event);	  
                        	}
				
			}


                break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            printf("Game Over !\n");
                            break;
			case SDLK_x:
			    displayIMG(I[3],screen);
			    loop = 0;
			    break;
                    }
		if(event.key.keysym.sym==SDLK_p)
		{
		    Mix_PlayChannel(-1, son, 0);
		    displayIMG(I[1],screen);
			    
		}
		if(event.key.keysym.sym==SDLK_s)
		{
		    Mix_PlayChannel(-1, son, 0);
		    displayIMG(I[2],screen);
		}
                    break;
                
                case SDL_MOUSEBUTTONDOWN:
                    printf("you cliked the mouse !\n");
		    if(event.motion.x>=1083 && event.motion.x<=1083+328 && event.motion.y>=614 && event.motion.y<=614+75)
		    {
			Mix_PlayChannel(-1, son, 0);
			loop=0;
		    }
		    if(event.motion.x>=1083 && event.motion.x<=1083+328 && event.motion.y>=490 && event.motion.y<=490+74)
		    {
			Mix_PlayChannel(-1, son, 0);
		    }
		    if(event.motion.x>=1083 && event.motion.x<=1083+328 && event.motion.y>=371 && event.motion.y<=371+80)
		    {
			Mix_PlayChannel(-1, son, 0);
		    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    printf("you cliked the mouse UP !\n");
		    if(event.motion.x>=1083 && event.motion.x<=1083+328 && event.motion.y>=490 && event.motion.y<=490+74)
			{
				while(event.key.keysym.sym !=SDLK_ESCAPE)
				{
				   displayIMG(I[4],screen);
				   displayIMG(I[9],screen);
				   SDL_Flip(screen);
				   SDL_PollEvent(&event);
				   
				   switch(event.type)
				{
					case SDL_KEYDOWN:
				   if(event.key.keysym.sym==SDLK_w)
				   {
					Mix_VolumeMusic(MIX_MAX_VOLUME/8);
					if(I[9].dist.x>0)
					{I[9].dist.x = 0;}
					else if(I[9].dist.x>-100)
					{I[9].dist.x = I[9].dist.x - 100;}

					
				   }
				   if(event.key.keysym.sym==SDLK_v)
				   {
					Mix_VolumeMusic(MIX_MAX_VOLUME);
					if(I[9].dist.x<0)
					{I[9].dist.x = 0;}
					else if(I[9].dist.x<100)
					{I[9].dist.x = I[9].dist.x + 100;}

					
				   }
				   if(event.key.keysym.sym==SDLK_f)
				   {
					screen=SDL_SetVideoMode(1900,1200,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
				   }
				   if(event.key.keysym.sym==SDLK_m)
				   {
					screen=SDL_SetVideoMode(1600,900,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
				   }
					break;
				}
                        	}
			}
		   if(event.motion.x>=1083 && event.motion.x<=1083+328 && event.motion.y>=371 && event.motion.y<=371+80)
			{
			    while(event.key.keysym.sym !=SDLK_ESCAPE)
				{
				   //printf("X=%d||Y=%d\n",event.motion.x,event.motion.y);
				   displayIMG(I[8],screen);
				   SDL_Flip(screen);
				   SDL_PollEvent(&event);
				   switch(event.type)
				   {
					case SDL_MOUSEMOTION:
					if(event.motion.x>=496 && event.motion.x<=496+262 && event.motion.y>=355 && event.motion.y<=355+352)
					{
							displayIMG(I[10],screen);
							SDL_Flip(screen);
					}
				  	if(event.motion.x>=837 && event.motion.x<=837+262 && event.motion.y>=355 && event.motion.y<=355+352)
					{
							displayIMG(I[11],screen);
							SDL_Flip(screen);
					}
					break;
					
					case SDL_KEYDOWN:
					    if(event.key.keysym.sym==SDLK_q)
					    {
						displayIMG(I[10],screen);
						SDL_Flip(screen);
						
					    }
					    if(event.key.keysym.sym==SDLK_d)
					    {
						displayIMG(I[11],screen);
						SDL_Flip(screen);
					    }
						
					
					break;
					case SDL_MOUSEBUTTONDOWN:
					if(event.motion.x>=622 && event.motion.x<=622+336 && event.motion.y>=798 && event.motion.y<=798+86)
					{
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						displayIMG(I[12],screen);
						SDL_Flip(screen);
					}
					break;
				   }
				   
                        	}
			}
		    
		    
                    break;
		case SDL_MOUSEMOTION:
                    
			if(event.motion.x>=1083 && event.motion.x<=1083+328 && event.motion.y>=371 && event.motion.y<=371+80)
			{
			    displayIMG(I[1],screen);
			}
			if(event.motion.x>=1083 && event.motion.x<=1083+328 && event.motion.y>=490 && event.motion.y<=490+74)
			{
			    displayIMG(I[2],screen);
			}
			if(event.motion.x>=1083 && event.motion.x<=1083+328 && event.motion.y>=614 && event.motion.y<=614+75)
			{
			    displayIMG(I[3],screen);
			}
			SDL_Flip(screen); 
                    break;
            }
 
	SDL_Flip(screen);  
    }
    screen=NULL;
    I[0].img=NULL;
    Mix_FreeChunk(son);
    Mix_FreeMusic(m);
    clean(screen);
    clean(I[0].img);
    SDL_Quit();
    

    return 0;
}
