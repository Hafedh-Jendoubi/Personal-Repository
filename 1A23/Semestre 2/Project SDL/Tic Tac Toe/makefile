game: main.o tic.o image.o text.o
	gcc main.o tic.o image.o text.o -o game -lSDL -lSDL_image -lSDL_ttf -g -lSDL_mixer
main.o: main.c
	gcc -c main.c -g
tic.o: tic.c
	gcc -c tic.c -g
image.o: image.c
	gcc -c image.c -g
text.o: text.c
	gcc -c text.c -g
