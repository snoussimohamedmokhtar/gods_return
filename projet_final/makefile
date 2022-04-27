prog: main.o image.o texte.o
	gcc main.o image.o texte.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
image.o:image.c
	gcc -c image.c -g
texte.o:texte.c
	gcc -c texte.c -g
