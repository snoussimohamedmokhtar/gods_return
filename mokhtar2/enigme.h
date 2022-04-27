#ifndef ENIGME_H
#define ENIGME_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
/**
* @struct enigme
* @brief struct for enigme
*/

typedef struct 
{
	SDL_Surface *background;/*!< Surface. */
	SDL_Surface *won;
	SDL_Surface *lost;
	SDL_Surface *clock;

	
	SDL_Rect pos_back;/*!< Rectangle*/
	SDL_Rect pos_wonlose;
	SDL_Rect pos_clock;
	int num_question;
	int rep_vrai;
	int rep_joueur;
	int etat;
	int x; 
	int y; 
	int score_enigme;
	int frame;
	int lastTime;
	int currentTime;
}enigme;

void initEnigme(enigme *e , char *nomfichier);
void afficherEnigme(enigme *e, SDL_Surface * s);
void animer (enigme *e);
//void sauvgarder( personne *p,background b ,char*nomfichier);
//int charger ( personne *p , background *b, char *nomfichier );


#endif 
