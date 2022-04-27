
#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <math.h>
#include <time.h>
#include "string.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "gestiontemp.h"
#include "SDL_rotozoom.h"

void init_background ( background* bg)
{
	bg->bg = IMG_Load("background.png");
	bg->pos_bg.x = 0;
	bg->pos_bg.y = 0;

	bg->pos_scrolling.x = 0;
	bg->pos_scrolling.y = 0;
	bg->pos_scrolling.w = 800;
	bg->pos_scrolling.h = 600;

	bg->end_scrolling_right = 0;
	bg->end_scrolling_left = 0;
}

void blit_background(background* bg,SDL_Surface *screen)
{
	SDL_BlitSurface(bg->bg,&bg->pos_scrolling,screen,&bg->pos_bg);
}


void scrolling_right (background* bg) 
{
	if ( bg->pos_scrolling.x <= 800 )
	{
		bg->pos_scrolling.x +=20;
		bg->end_scrolling_right = 0;
	}
	else{
		bg->end_scrolling_right = 1;

	}

}

void scrolling_left (background* bg ) 
{

	if ( bg->pos_scrolling.x >= 20 )
	{
		bg->pos_scrolling.x -=20;
		bg->end_scrolling_left = 0;
	}
	else{
		bg->end_scrolling_left = 1;
	}

	

}


void free_background(background* bg)
{
	SDL_FreeSurface(bg->bg);
}


void init_minimap(minimap* mp)
{
	mp->mini_map = IMG_Load("minimap.png");
	mp->pos_minimap.x = 300;
	mp->pos_minimap.y = 50;
	mp->mini_hero = IMG_Load("mini_perso.png");
	mp->pos_minihero.x = 300;
	mp->pos_minihero.y = 130;
}


void blit_minimap( minimap* mp,SDL_Surface *screen)
{
	SDL_BlitSurface(mp->mini_map,NULL,screen,&mp->pos_minimap);
	SDL_BlitSurface(mp->mini_hero,NULL,screen,&mp->pos_minihero);
}


void dep_mini_hero (SDL_Rect* pos_perso,minimap *mp , SDL_Rect camera,int redimensionnement,int sens,float size)
{
	SDL_Rect temp;
	temp.x =( (*pos_perso).x*redimensionnement )/150;
	temp.y =( (*pos_perso).y*redimensionnement )/150;
	if ( sens == 0 )
	{
		if (mp->pos_minihero.x <= 610 + (610*size)/100 )
			mp->pos_minihero.x = 300 + temp.x + (300*size)/40;
			if ( (*pos_perso).y > -450 && (*pos_perso).y < 170 )
				mp->pos_minihero.y = 130 + temp.y  + (130*size)/30;
	}
	else
	{
		if (mp->pos_minihero.x > 300 + (300*size)/100 )
			mp->pos_minihero.x = 300 + temp.x + (300*size)/40 ;
			if ( (*pos_perso).y > -450 && (*pos_perso).y < 170 )
				mp->pos_minihero.y = 130 + temp.y + (130*size)/30 ;
	}
	//mp->pos_minihero.y += temp.y;
	printf("%d : %d \n " , mp->pos_minihero.x ,  mp->pos_minihero.y);
	
}

void free_minimap(minimap* mp)
{
	SDL_FreeSurface(mp->mini_map);
	SDL_FreeSurface(mp->mini_hero);
}


void singleplayer( SDL_Surface *screen )
{



    SDL_Rect pos_hero,frame,pos_hero_init;
    SDL_Surface* hero = IMG_Load("hero_spr.png");
    pos_hero.x = 0;
    pos_hero.y = 0;

    pos_hero_init.x = pos_hero.x;
    pos_hero_init.y = 385;

    frame.x =  0;
    frame.y =  0;
    frame.w =  100;
    frame.h =  100;

//###################################################


    background bg;
    init_background(&bg);

    minimap mp;
    init_minimap(&mp);

	int test_scrolling_end_right = 0,test_scrolling_end_left = 0;

//###################################################

//////////// temps

    temps t;
    char temps[200]="";
    TTF_Init();
    SDL_Color couleurblanche = {255, 255, 255};
    inittemps(&t);
    t.tempsActuel=SDL_GetTicks();
    int start;

/////////// score

    score s;
    char score[200]="";
    TTF_Init();
    initscore(&s);



//###################################################
    SDL_Event event;
    SDL_WM_SetCaption("game",NULL);

    int sens=2;




    double size = 1;
    int continuer=1;
    while(continuer == 1)
    {
        start = SDL_GetTicks(); // temps actuel
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



            case SDLK_LSHIFT :
            {
		if ( size < 3 ){
			size += 1;
			mp.mini_map = rotozoomSurface ( mp.mini_map, 0 , 1.10 , 0);
			mp.mini_hero = rotozoomSurface ( mp.mini_hero, 0 , 1.10 , 0);
		}

	    }break;

            case SDLK_LCTRL :
            {
		if ( size > 1 ){
			size -= 1;
			mp.mini_map = rotozoomSurface ( mp.mini_map, 0 , 0.91 , 0);
			mp.mini_hero = rotozoomSurface ( mp.mini_hero, 0 , 0.91 , 0);
		}

	    }break;


            case SDLK_RIGHT :
            {
		scrolling_right(&bg);
                sens = 0;
		if ( bg.end_scrolling_right != 0 ){
			pos_hero_init.x +=20;
		}
			pos_hero.x +=30;

            }
            break;

            case SDLK_LEFT :
            {
		scrolling_left(&bg);
                sens = 1;
                if ( bg.end_scrolling_left != 0 ){
			pos_hero_init.x -=20;
		}
			pos_hero.x -=30;

            }
            break;

	    case SDLK_UP :
            {
		pos_hero.y -=20;
		pos_hero_init.y -=20; 

            }
            break;

	    case SDLK_DOWN :
            {

		if ( pos_hero_init.y < 500 ){
		pos_hero.y +=20;
		pos_hero_init.y +=20;}

            }
            break;

            }
            break;

	

        }// taskiret les events mtaa les boutons
                dep_mini_hero (&pos_hero,&mp,frame,20,sens,size);
	blit_background(&bg,screen);

	updatescore(&s);
	affichage_score(&s,score);
	blitscore(&s,screen);
 

        updatetemps(&t);
	affichage_temps(&t,temps);
        blitTemps(&t,screen);

	//printf("%d" , bg.pos_scrolling.x);

        blit_minimap(&mp,screen);
        SDL_BlitSurface(hero,&frame,screen,&pos_hero_init);
        SDL_Flip(screen);
        SDL_Delay(80);

    } // taskiret continuer
    free_background(&bg);
    SDL_FreeSurface(hero);
    free_minimap(&mp);
    free_temps(&t);
    free_score(&s);
}









void init_background_bottom ( background* bg)
{
	bg->bg = IMG_Load("background.png");
	bg->pos_bg.x = 0;
	bg->pos_bg.y = 600;

	bg->pos_scrolling.x = 0;
	bg->pos_scrolling.y = 0;
	bg->pos_scrolling.w = 800;
	bg->pos_scrolling.h = 600;

	bg->end_scrolling_right = 0;
	bg->end_scrolling_left = 0;

}

void blit_background_bottom(background* bg,SDL_Surface *screen)
{
	SDL_BlitSurface(bg->bg,&bg->pos_scrolling,screen,&bg->pos_bg);
}





void free_background_bottom(background* bg)
{
	SDL_FreeSurface(bg->bg);
}


void init_minimap_bottom(minimap* mp)
{
	mp->mini_map = IMG_Load("minimap.png");
	mp->pos_minimap.x = 300;
	mp->pos_minimap.y = 650;
	mp->mini_hero = IMG_Load("mini_perso.png");
	mp->pos_minihero.x = 300;
	mp->pos_minihero.y = 730;
}


void blit_minimap_bottom( minimap* mp,SDL_Surface *screen)
{
	SDL_BlitSurface(mp->mini_map,NULL,screen,&mp->pos_minimap);
	SDL_BlitSurface(mp->mini_hero,NULL,screen,&mp->pos_minihero);
}


void dep_mini_hero_bottom (SDL_Rect* pos_perso,minimap *mp , SDL_Rect camera,int redimensionnement,int sens)
{
	SDL_Rect temp;
	temp.x =( (*pos_perso).x*redimensionnement )/150;
	temp.y =( (*pos_perso).y*redimensionnement )/150;
	if ( sens == 0 )
	{
		if (mp->pos_minihero.x <= 610 )
			mp->pos_minihero.x = 300 + temp.x;
			mp->pos_minihero.y = 730 + temp.y;
	}
	else
	{
		if (mp->pos_minihero.x > 300 )
			mp->pos_minihero.x = 300 + temp.x ;
			mp->pos_minihero.y = 730 + temp.y;
	}
	//mp->pos_minihero.y += temp.y;
	
}

void free_minimap_bottom(minimap* mp)
{
	SDL_FreeSurface(mp->mini_map);
	SDL_FreeSurface(mp->mini_hero);
}


void multiplayer ( SDL_Surface *screen )
{

    screen=SDL_SetVideoMode(800,1200, 32,SDL_HWSURFACE| SDL_DOUBLEBUF);

    SDL_Rect pos_hero,pos_hero_bottom,frame,pos_hero_init,pos_hero_init_bottom;
    SDL_Surface* hero = IMG_Load("hero_spr.png");
    pos_hero.x = 0;
    pos_hero.y = 385;

    pos_hero_init.x = pos_hero.x;
    pos_hero_init.y = 385;

    frame.x =  0;
    frame.y =  0;
    frame.w =  100;
    frame.h =  100;


    pos_hero_bottom.x = 0;
    pos_hero_bottom.y = 985;

    pos_hero_init_bottom.x = pos_hero_bottom.x;
    pos_hero_init_bottom.y = 985;


//###################################################


    background bg, bg_bottom;
    init_background(&bg);
    init_background_bottom(&bg_bottom);

    minimap mp,mp_bottom;
    init_minimap(&mp);
    init_minimap_bottom(&mp_bottom);

	int test_scrolling_end_right = 0,test_scrolling_end_left = 0;
	int test_scrolling_end_right_bottom = 0,test_scrolling_end_left_bottom = 0;

//###################################################


    SDL_Event event;
    SDL_WM_SetCaption("game",NULL);

    int sens=0,sens_bottom=0;;





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
		scrolling_right(&bg);
                sens = 0;
		if ( bg.end_scrolling_right == 0 ){
			pos_hero.x +=30;
		}
                //dep_mini_hero (&pos_hero,&mp,frame,20,sens);
            }
            break;

            case SDLK_LEFT :
            {
		scrolling_left(&bg);
                sens = 1;
                if ( bg.end_scrolling_left == 0 ){
			pos_hero.x -=30;
		}
               // dep_mini_hero (&pos_hero,&mp,frame,20,sens);
            }
            break;


	    case SDLK_d :
            {
		scrolling_right(&bg_bottom);
                sens_bottom = 0;
                if ( bg_bottom.end_scrolling_right == 0 ){
			pos_hero_bottom.x +=30;
		}
                dep_mini_hero_bottom (&pos_hero_bottom,&mp_bottom,frame,20,sens_bottom);
            }
            break;

            case SDLK_q :
            {
		scrolling_left(&bg_bottom);
                sens_bottom = 1;
                if ( bg_bottom.end_scrolling_left == 0 ){
			pos_hero_bottom.x -=30;
		}
                dep_mini_hero_bottom (&pos_hero_bottom,&mp_bottom,frame,20,sens_bottom);
            }
            break;

           
            }
            break;


        }// taskiret les events mtaa les boutons


	printf("%d" , bg.pos_scrolling.x);
	blit_background(&bg,screen);
        blit_minimap(&mp,screen);
        SDL_BlitSurface(hero,&frame,screen,&pos_hero_init);

	blit_background_bottom(&bg_bottom,screen);
        blit_minimap_bottom(&mp_bottom,screen);
        SDL_BlitSurface(hero,&frame,screen,&pos_hero_init_bottom);

        SDL_Flip(screen);
        SDL_Delay(60);

    } // taskiret continuer
    free_background(&bg);
    SDL_FreeSurface(hero);
    free_minimap(&mp);

    free_background_bottom(&bg_bottom);
    free_minimap_bottom(&mp_bottom);


}






























