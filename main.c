#include <stdio.h>
#include "include/raylib.h"

#define width  800
#define height 640

int main()
{
    InitWindow(width, height, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangle(100, 100, 20, 20, GREEN);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}