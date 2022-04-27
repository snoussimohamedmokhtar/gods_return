prog: main.o fonctions.o gestiontemp.o SDL_rotozoom.o
	gcc main.o fonctions.o gestiontemp.o SDL_rotozoom.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm

main.o:main.c
	gcc -c main.c
fonctions.o:fonctions.c
	gcc -c fonctions.c
gestiontemp.o:gestiontemp.c
	gcc -c gestiontemp.c
SDL_rotozoom.o:SDL_rotozoom.c
	gcc -c SDL_rotozoom.c









