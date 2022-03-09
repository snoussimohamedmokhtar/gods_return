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
    SDL_Surface *screen;
    SDL_Event event;
    image I[10];
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


    INIT_IMGB(&I[0],"/home/mokhtar/jeu_tab/menu.png");
    INIT_IMGB(&I[1],"/home/mokhtar/jeu_tab/play_on(1).png");
    INIT_IMGB(&I[2],"/home/mokhtar/jeu_tab/settings_on(1).png");
    INIT_IMGB(&I[3],"/home/mokhtar/jeu_tab/exit_on(1).png");
    INIT_IMGB(&I[4],"/home/mokhtar/jeu_tab/settings_menu_mini_.png");
    INIT_IMGB(&I[5],"/home/mokhtar/jeu_tab/1_.png");
    INIT_IMGB(&I[6],"/home/mokhtar/jeu_tab/2_.png");
    INIT_IMGB(&I[7],"/home/mokhtar/jeu_tab/3_.png");
    INIT_IMGB(&I[8],"/home/mokhtar/jeu_tab/playbgnew.png");
    INIT_IMGB(&I[9],"/home/mokhtar/jeu_tab/volume_p.png");

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
				   displayIMG(I[8],screen);
				   SDL_Flip(screen);
				   SDL_PollEvent(&event);
				   
                        	}
			}
		    
		    
                    break;
		case SDL_MOUSEMOTION:
                    printf("X=%d||Y=%d\n",event.motion.x,event.motion.y);
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
