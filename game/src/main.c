#include <stdio.h>
#include "raylib.h"


#define FPS 60
#define DT (1./FPS)

Color colors[] = {
        RED,      ORANGE, GOLD,    YELLOW,
        GREEN,    LIME,   SKYBLUE, BLUE,
        DARKBLUE, VIOLET, PURPLE,  DARKPURPLE
};

int main(void){
    int WIDTH = 800;
    int HEIGHT = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(WIDTH, HEIGHT, "Hello world");
    SetTargetFPS(FPS);

    int fontSize = 50;
    char* text = "Raylib on Discord";
    int length = MeasureText(text, fontSize);

    Vector2 pos = {200, 200};
    Vector2 vel = {300, 300};

    int colorCount = 12;
    int i = 0;

    while(!WindowShouldClose()){
        if (IsWindowResized() && !IsWindowFullscreen()){
            WIDTH = GetScreenWidth();
            HEIGHT = GetScreenHeight();
        }

        pos.x += vel.x*DT;
        pos.y += vel.y*DT;

        if(pos.x < 0){              pos.x = 0;               vel.x = -vel.x; i++;}
        if(pos.x > WIDTH-length){   pos.x = WIDTH-length;    vel.x = -vel.x; i++;}
        if(pos.y < 0){              pos.y = 0;               vel.y = -vel.y; i++;}
        if(pos.y > HEIGHT-fontSize){pos.y = HEIGHT-fontSize; vel.y = -vel.y; i++;}

        BeginDrawing();
         ClearBackground(BLACK);
         DrawText(text, (int)pos.x, (int)pos.y, fontSize, colors[i%colorCount]);
        EndDrawing();
    }
    CloseWindow();
}