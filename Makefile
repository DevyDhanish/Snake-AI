all:
	gcc -c -Iinclude/ src/body.c -o body.o
	gcc -c -Llib/ src/list.c -o list.o
	gcc body.o list.o main.c -o snakeai -Iinclude/ -Llib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
