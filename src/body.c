#include "../include/body.h"
#include "../include/raylib.h"
#include <stdlib.h>

body *makeBody(int posx, int posy, Color color)
{
    body *newbody = (body*) malloc(sizeof(body));
    newbody->posx = posx;
    newbody->posy = posy;
    newbody->color = color;

    return newbody;
}

void flushBody(body *snake_body)
{
    free(snake_body);
}