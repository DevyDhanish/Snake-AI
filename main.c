#include <stdio.h>
#include "include/raylib.h"
#include "include/body.h"
#include "include/list.h"
#include <stdlib.h>
#include <unistd.h>

#define width  800
#define height 640

int snakex = 100;
int snakey = 100;
float speed = 1;

int direction = 1;      // +1 for X forward
                        // -1 for X backward
                        // +2 for Y forward
                        // -2 for Y backward

void printSnake(node *snakeBody)
{
    while(snakeBody)
    {
        body *curr_body = (body *) snakeBody->body_node;
        DrawRectangle(curr_body->posx, curr_body->posy, 20, 20, curr_body->color);
        printf("%d,%d\n", curr_body->posx, curr_body->posy);
        snakeBody = snakeBody->next;
    }
}

void updateBody(node *snakeBody)
{
    if (!snakeBody || !snakeBody->next)
    {
        return;
    }

    node *temp = snakeBody->next;
    int offsetx = 0;
    int offsety = 0;
    while (temp)
    {
        body *prev_body = temp->prev->body_node;
        temp->body_node->posx = prev_body->posx;
        temp->body_node->posy = prev_body->posy;
        temp = temp->next;
    }
}

int main()
{
    InitWindow(width, height, "Snake AI");
    SetTargetFPS(60);

    node *snakeBody = NULL;
    node *head = NULL;

    snakeBody = insert(snakeBody, makeBody(snakex, snakey, RED));
    head = snakeBody;
    snakeBody = insert(snakeBody, makeBody(snakex, snakey, GREEN));
    snakeBody = insert(snakeBody, makeBody(snakey, snakey, GREEN));
    snakeBody = insert(snakeBody, makeBody(snakey, snakey, GREEN));
    snakeBody = insert(snakeBody, makeBody(snakey, snakey, GREEN));
    snakeBody = insert(snakeBody, makeBody(snakey, snakey, GREEN));
    snakeBody = insert(snakeBody, makeBody(snakey, snakey, GREEN));
    snakeBody = insert(snakeBody, makeBody(snakey, snakey, GREEN));
    snakeBody = insert(snakeBody, makeBody(snakey, snakey, GREEN));
    snakeBody = insert(snakeBody, makeBody(snakey, snakey, GREEN));

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        snakeBody = head;

        if(IsKeyPressed(KEY_W)) { direction = +2; }   // up
        if(IsKeyPressed(KEY_S)) { direction = -2; }   // down
        if(IsKeyPressed(KEY_D)) { direction = +1; }   // right
        if(IsKeyPressed(KEY_A)) { direction = -1; }   // left

        switch (direction)
        {
        case  +1:
            head->body_node->posx += 1;
            break;
        case -1:
            head->body_node->posx -= 1;
            break;
        case +2:
            head->body_node->posy -= 1;
            break;
        case -2:
            head->body_node->posy += 1;
            break;
        default:
            break;
        }
        //usleep(100000);
        printSnake(snakeBody);
        updateBody(head);
        EndDrawing();
    }

    CloseWindow();

    flushList(snakeBody);

    return 0;
}