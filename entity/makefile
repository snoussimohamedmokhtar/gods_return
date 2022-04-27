prog: main.o entity.o perso.o
	gcc main.o entity.o perso.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
entity.o:entity.c
	gcc -c entity.c -g
perso.o:perso.c
	gcc -c perso.c -g
