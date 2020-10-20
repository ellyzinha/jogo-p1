#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

 //Inicialização
    
    const int screenWidth = 1200;
    const int screenHeight = 800;
    
    //Criando a estrutura do personagem principal
    typedef struct {
        Vector2 pos;
        Vector2 vel;
        Vector2 acc;
        Texture2D textura_stand;
        Texture2D textura_walk_right;
        Texture2D textura_walk_left;
        Texture2D textura_jump;
        Texture2D textura_attack;
        Texture2D textura_background;
        Rectangle sourceRec_stand;
        Rectangle sourceRec_walk_right;
        Rectangle sourceRec_walk_left;
        Rectangle sourceRec_jump;
        Rectangle sourceRec_attack;
        int frameAtual;
        int altura;
        int largura;
        float scrollingBack;
    }MISTY;
    
    void initMisty(MISTY* misty){
        misty->pos.x = 0;
        misty->pos.y = 650;
        misty->vel.y = 0;
        misty->vel.x = 0;
        misty->acc.y = 0.2;
        misty->acc.x = 0;
        misty->altura;
        misty->largura;
        misty->textura_stand = LoadTexture("./assets/WitchSprite/stand.png");
        Rectangle sr_stand = {0.0f, 0.0f, misty->textura_stand.width/4, misty->textura_stand.height};
        misty->sourceRec_stand = sr_stand;
        misty->textura_walk_right = LoadTexture("./assets/WitchSprite/walk.png");
        Rectangle sr_walk_right = {0.0f, 0.0f, misty->textura_walk_right.width/4, misty->textura_walk_right.height};
        misty->sourceRec_walk_right = sr_walk_right;
        misty->textura_walk_left = LoadTexture("./assets/WitchSprite/walk.png");
        Rectangle sr_walk_left = {0.0f, 0.0f, misty->textura_walk_left.width/4, misty->textura_walk_left.height};
        misty->sourceRec_walk_left = sr_walk_left;
        misty->textura_jump = LoadTexture("./assets/WitchSprite/jump.png");
        Rectangle sr_jump = {0.0f, 0.0f, misty->textura_jump.width/2, misty->textura_jump.height};
        misty->sourceRec_jump = sr_jump;
        misty->textura_attack = LoadTexture("./assets/WitchSprite/attack.png");
        Rectangle sr_attack = {0.0f, 0.0f, misty->textura_attack.width/3, misty->textura_attack.height};
        misty->sourceRec_attack = sr_attack;
       // misty->textura_background = LoadTexture("./background/level1/forest.png");
       // misty->scrollingBack = 0.0f;
        misty->frameAtual = 0;
    }
    
    void updateMisty(MISTY* misty) {
        static int frameCounter = 0;
        frameCounter++;
        
        if(frameCounter > 10) {
            frameCounter = 0;
            misty->frameAtual++;
            
            if(misty->frameAtual > 5) {
                misty->frameAtual = 0;
            }
        }
        
        if(IsKeyDown(KEY_RIGHT)){
            
        }
    }


int main(void) {
    
   
    
    InitWindow(screenWidth, screenHeight, "Coven");
    
    Texture2D misty = LoadTexture("./assets/WitchSprite/stand.png");
    
    
    while (!WindowShouldClose()) {
        
        BeginDrawing();
        
            ClearBackground(RAYWHITE);

            DrawTexture(misty, screenWidth/2 - misty.width/2, screenHeight/2 - misty.height/2, WHITE);
        
        EndDrawing();
        
    }
    
    UnloadTexture(misty);
    
    CloseWindow();
    
    return 0;
}