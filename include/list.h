#ifndef LIST_H
#define LIST_H

#include "body.h"

struct node
{
    body *body_node;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

node *insert(node *, body *);

void flushList(node *);

#endif