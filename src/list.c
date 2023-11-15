#include "../include/list.h"
#include "../include/body.h"

#include <stdlib.h>

node *insert(node *head, body *snake_body)
{
    node *newNode = (node *) malloc(sizeof(node));
    newNode->body_node = snake_body;
    newNode->next = NULL;

    if(!head)
    {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }

    node *temp = head;
    while(temp->next) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void flushList(node *head)
{
    node *temp = head;
    while(temp)
    {
        node *nodeToRemove = temp;
        temp = temp->next;
        flushBody(nodeToRemove->body_node);
        free(nodeToRemove);
    }
}