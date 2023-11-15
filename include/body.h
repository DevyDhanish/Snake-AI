#ifndef BODY_H
#define BODY_H

#include "raylib.h"

struct snake_body
{
    int posx;
    int posy;
    Color color;
};

typedef struct snake_body body;

body *makeBody(int , int, Color);

void flushBody(body *);

#endif