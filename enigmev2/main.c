#include <stdio.h>
#include "SDL/SDL.h"
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

#include "enigme.h"

int main()
{
	SDL_Surface *ecran =NULL;
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(1600, 900, 32, SDL_HWSURFACE );
	
	
	image I[2]; //image "you win" , " you lose" 
        INIT_IMGB(&I[0],"/home/ahmedb/enigmev2/You-win.png"); 
        INIT_IMGB(&I[1],"/home/ahmedb/enigmev2/wrong.png"); 
         


        // SOUND

    if(Mix_OpenAudio(48000,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
	printf("%s",Mix_GetError());
	}
	     
      
      
       Mix_Chunk * son1;
      son1= Mix_LoadWAV( "/home/ahmedb/enigmev2/Victory sound effect.wav"); 
       Mix_Chunk * son2;
      son2= Mix_LoadWAV( "/home/ahmedb/enigmev2/Videogame Lose Sound Effect HD _ No Copyright(1).wav"); 
     
	
	enigme e;
	
	int cycle =1;
	
	char nomfichier[20]="";
	SDL_Event event;

	
	int k=0; //inisialisation pointeur pour démarer
	int collision_enigme=1; //el ON switch enigme (condition vrai)

	while (cycle==1)
    	{

	    	SDL_PollEvent(&event);
	    	SDL_Flip(ecran);
	    	
	    	
	    	if ((k==0)&&(collision_enigme=1))
	    	{
	    		initEnigme(&e,nomfichier);
	    		collision_enigme=0; // off switch of the condition 
	    		k=1;
	    	}
	    	
		    	if(k==1)
		    	{ 
		    	  afficherEnigme(&e,ecran);		
		    	  animer(&e);
		    	
		    	}
		    	
		    	
		    	
	    	switch (event.type)
		{
				case SDL_KEYDOWN:
				   		 switch (event.key.keysym.sym)
				  		  {
							case SDLK_a:
								if(k==1)
									{	
										e.rep_joueur=1;
										afficherEnigmetext(&e,ecran,1);
								        }
							break;
							case SDLK_b:
								if(k==1)
									{	
										e.rep_joueur=2;
										afficherEnigmetext(&e,ecran,2);
									}
							break;
							case SDLK_c:
								if(k==1)
									{
										e.rep_joueur=3;
										afficherEnigmetext(&e,ecran,3);
									}
							break;
						  } 
				break;
				 case SDL_MOUSEBUTTONDOWN: 
						   printf("**you cliked the mouse !**\n");
						   if(event.motion.x>=678 && event.motion.x<=678+258 && event.motion.y>=470 && event.motion.y<=470+54)
						   {
							e.rep_joueur=1;
							afficherEnigmetext(&e,ecran,1);
						   }
						   
						   if(event.motion.x>=678 && event.motion.x<=678+258 && event.motion.y>=567 && event.motion.y<=567+47)
						   {
							e.rep_joueur=2;
							afficherEnigmetext(&e,ecran,2);
							
						   }
						   
						   if(event.motion.x>=678 && event.motion.x<=678+258 && event.motion.y>=667 && event.motion.y<=667+43)
						   {
						       e.rep_joueur=3;
						       afficherEnigmetext(&e,ecran,3);
						    
						   }
			   
                    break;
				
	   	}
	   		
	   		
	   			if(k==1)
	   			{
			   			if(e.rep_joueur!=0)
			   			{
			   			       
			   				 k=0;
			   				if (e.rep_joueur==e.reponse_vrai)
			   				{
			   						
			   				         	Mix_PlayChannel(-1, son1, 0);
			   				         	
			   				         	displayIMG(I[0],ecran);
			   						printf("GOOD ANSWER !!\n");
			   						printf("score: +10\n");
			   						printf("*********\n");	
			   						
			   				}	
			   				else
				   				{ 	
				   			      		Mix_PlayChannel(-1, son2, 0);
				   			    	
				   			       	displayIMG(I[1],ecran);
				   					printf("WRONGGGG !\n");
				   					printf("score: -10\n");
				   					printf("*********\n");
				   					 
				   		 
				   				}
				   		
				   		
		   				}
		   				
		   				SDL_Flip(ecran);
		   				if(e.rep_joueur!=0)
			   	{
	   			SDL_Delay(5000);
				cycle=0;	
	   			}
		   				
	   			}
	   			
	   			
   			
}


return 0;
}
