/**
* @file entity.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
#include"entity.h"
/**
* @brief To initialize the entity .
* @param ennemi enemy 
* @return Nothing
*/
void init_Entity(Entity *ennemi)
{
    //init spritesheet :

    ennemi->Spritesheet=IMG_Load("/home/yassine/test ES/ennemi transparent-02.png");
    

    //initialisation de la position de l'ennemi : 

    ennemi->position.x=400;
    ennemi->position.y=300;
    ennemi->position.w=172;
    ennemi->position.h=183;

    //animation position :

    ennemi->animation.x=0;
    ennemi->animation.y=0;
    ennemi->animation.w=172;
    ennemi->animation.h=183;

    //init ennemi direction :

    ennemi->direction=1;     
}
/**
* @brief To afficher ennemi
* @param screen
* @param ennemi
* @param backg
* @return Nothing
*/
void afficher_ennemi(SDL_Surface *Screen, Entity ennemi,SDL_Surface *backg)
{
   SDL_BlitSurface(backg,NULL,Screen,NULL); 
   SDL_BlitSurface(ennemi.Spritesheet,&ennemi.animation,Screen,&ennemi.position);
}
/**
* @brief To existance collision
* @param player
* @param ennemi
* @return 1 ou 0
*/
int collisionBB(Entity *ennemi, Player *hero)
{
    if(ennemi->position.x+ennemi->position.w > hero->position.x && ennemi->position.x < hero->position.x+hero->position.w && ennemi->position.y+ennemi->position.h > hero->position.y && ennemi->position.y < hero->position.y+hero->position.h)
        return 1;
    else
        return 0;
}
/**
* @brief To deplacer ennemi
* @param player p
* @param ennemi
* @return Nothing
*/
void movment(Entity *ennemie,Player p)
{
    if(ennemie->direction == 1)
    {
        ennemie->position.x +=10;
        if(ennemie->position.x + ennemie->position.w > 1200)
            ennemie->direction=0;
    }

    if(ennemie->direction==0)
    {
       ennemie->position.x-=10;
        if (ennemie->position.x <400 && p.position.x<100)
            ennemie->direction=1;
        
    }
}
/**
* @brief To animer ennemi
* @param ennemi
* @return Nothing
*/
void annimation( Entity *ennemi)
{
   
        if(ennemi->direction==1)
        {
            ennemi->animation.y=0;
            ennemi->animation.x+=172;
            if(ennemi->animation.x>860)
                ennemi->animation.x=0;
        }

        if(ennemi->direction==0)    
        {
            ennemi->animation.y=183;
            ennemi->animation.x+=172;
            if(ennemi->animation.x>860)
                ennemi->animation.x=0;
        }
        
    
}
/**
* @brief To following player
* @param ennemi
* @param player
* @return Nothing
*/
void deplacerIA(Entity *e,Player p)
{
	if (p.position.x<e->position.x) //hero à gauche de l'ennemi
	{
		e->direction=0;
		movment(e,p);
	}

	if (p.position.x>e->position.x) // hero a droite
	{
		e->direction=1;
		movment(e,p);
	}
}






//
