all:
	gcc -I/usr/include -O3 -I./minilibx-linux/ -g   -c -o main.o main.c
	gcc -o hola_patata main.o -L./minilibx-linux/ -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
