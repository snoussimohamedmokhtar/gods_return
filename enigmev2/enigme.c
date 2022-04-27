#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h> 
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "enigme.h"



void initEnigme(enigme *e,char *nomfichier)
{
//****random

	int random;
        int i ;    
 
	srand(time(NULL));
	random =((rand()%3)+1); //random 1-->3
	
	
	
	
	switch (random)
	{ case 1 :
	  e->ligne_question =1 ;
	  break;
	  case 2 :
	  e->ligne_question=7;
	  break;
	  case 3 :
	  e->ligne_question =13; 
	  break;
	}
	

      	e->lastTime=0;
      
      
       char nomfichier2[500];
       int m=10;
       sprintf(nomfichier2,"question%d",m);


//partie fichier
	
	
	FILE * f=NULL;
	f=fopen(nomfichier2 ,"r");


	
	 char vide[100]="" ;

	char question[60]="";
	char rep1[100],rep2[100],rep3[100];
	e->rep_joueur=0;
	e->frame=1;
	
	
	
	if(f!=NULL){
	
				
				
				for (i=0;i< (e->ligne_question); i++)
				{
				fgets(vide,100,f);
				}
												
					 fgets(question,60, f);//1ere line
					 fgets(rep1,100,f);//2eme line
					 fgets(rep2,100,f);// 3eme line
					 fgets(rep3,100,f);// 4eme line
					 fscanf(f,"%d",&e->reponse_vrai);// numéro de la vrai reponse
					
		    }
	fclose(f);
	
	
	printf("question number :%d\n",random); 
	printf("true answer :%d\n", e->reponse_vrai);


	e->background=IMG_Load("1.png");//image load 
	e->picAnim=IMG_Load("1_.png");

// image color 

	SDL_Color color;
   	color.r = 255 ;
  	color.g = 255 ;
   	color.b = 255 ;
   	
   	SDL_Color color0;
   	color0.r = 102 ;
  	color0.g = 255 ;
   	color0.b = 153 ;
   	
   	

   ///****************TEXT********************
	TTF_Init();
	TTF_Font *font = NULL;
	font=TTF_OpenFont("kkm.ttf",30);
	
	e->question= TTF_RenderText_Solid(font,question,color); 
	e->reponses[0]= TTF_RenderText_Solid(font,rep1,color);
	e->reponses[1]= TTF_RenderText_Solid(font,rep2,color);
	e->reponses[2]= TTF_RenderText_Solid(font,rep3,color);




	e->reponsesvert[0]= TTF_RenderText_Solid(font,rep1,color0);
	e->reponsesvert[1]= TTF_RenderText_Solid(font,rep2,color0);
	e->reponsesvert[2]= TTF_RenderText_Solid(font,rep3,color0);

	
	
	

	e->pos_backbackground.x=0;
	e->pos_backbackground.y=0;

	e->pos_question.x=603;
	e->pos_question.y=345;

	e->pos_reponse1.x=678;
	e->pos_reponse1.y=470;

	e->pos_reponse2.x=678;
	e->pos_reponse2.y=567;

	e->pos_reponse3.x=678;
	e->pos_reponse3.y=667;

}

void afficherEnigme(enigme *e, SDL_Surface * s)
{
	SDL_BlitSurface(e->background,NULL,s,&e->pos_backbackground);
	SDL_BlitSurface(e->question,NULL,s,&e->pos_question);
	SDL_BlitSurface(e->reponses[0],NULL,s,&e->pos_reponse1);	
	SDL_BlitSurface(e->reponses[1],NULL,s,&e->pos_reponse2);	
	SDL_BlitSurface(e->reponses[2],NULL,s,&e->pos_reponse3);	
	SDL_BlitSurface(e->picAnim,NULL,s,&e->pos_backbackground);
}

void afficherEnigmetext(enigme *e, SDL_Surface *s,int b)
{
	switch (b)
	{
	case 1 :
	SDL_BlitSurface(e->reponsesvert[0],NULL,s,&e->pos_reponse1);	
	break ;
	case 2 :
	SDL_BlitSurface(e->reponsesvert[1],NULL,s,&e->pos_reponse2);	
	break ;
	case 3:
	SDL_BlitSurface(e->reponsesvert[2],NULL,s,&e->pos_reponse3);
	break ;
	}
}




SDL_Surface *LoadIMG(char nom[50])
 {
	SDL_Surface *img;
	img=IMG_Load(nom);
	if(img==NULL)
	{
	printf("%s faild load",nom);
	}  
	return img;
 }
 
 
void INIT_IMGB(image *I,char nom[20])
{
    I->img=LoadIMG(nom);
    I->src.x=0;
    I->src.y=0;
    I->src.w=626;
    I->src.h=417;

    I->dist.x=0;
    I->dist.y=0;
    I->dist.w=626;
    I->dist.h=417;
}

void displayIMG(image I,SDL_Surface *ecran)
{
    SDL_BlitSurface(I.img,NULL,ecran,&I.dist);
}



void animer (enigme *e)
{
	e->currentTime = SDL_GetTicks();
	if (e->currentTime > e->lastTime +350)
	 {
		char dublicate[50];
		sprintf(dublicate,"%d_.png",e->frame);
		e->picAnim=IMG_Load(dublicate);
		e->frame=e->frame+1;
		
		if(e->frame==4)
		{
		e->frame=1;	
		}	
		e->lastTime = e->currentTime;
  	}
	

}
