all:
	gcc main.c -Iinclude/ -Llib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11