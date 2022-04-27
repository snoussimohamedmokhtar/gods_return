#include"texte.h"
TTF_Font *INIT_FONT(char nom[20])
{
    TTF_Font *font;
    font=TTF_OpenFont(nom,20);
	if(font==NULL)
	{
		printf("font title load failed ");
	}
    return font;
}
void INIT_texte(texte *T,char nom[20])
{
	T->font=INIT_FONT(nom);
	T->pos.x=50;
	T->pos.y=850;
	T->TColor.r=255;
	T->TColor.g=255;
	T->TColor.b=255;
	T->font=NULL;
	T->font=TTF_OpenFont(nom,40);
	if(T->font==NULL)
	{
		printf("font title load failed ");
	}
    strcpy(T->text,"IT DOMINATORS");
	if(T->surtext==NULL)
	{
		printf("render title failed");
	}
}
void displayText(texte t,SDL_Surface *screen)
{
	t.surtext=TTF_RenderText_Solid(t.font,t.text,t.TColor);
	SDL_BlitSurface(t.surtext,NULL,screen,&t.pos);
}
