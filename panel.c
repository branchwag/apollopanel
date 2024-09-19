#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int main(void) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Apollo Panel");
	SetTargetFPS(60);
	
	int frameCount = 0;
	int rectWidth = 400;
	int rectHeight = 500;
	int marginTop = 10;
	int marginSide = 30;

	int posX = SCREEN_HEIGHT - rectWidth - marginSide;
	int posY = marginTop;

	while (!WindowShouldClose()) {
	  frameCount++;
	  BeginDrawing();
	  ClearBackground(DARKGRAY);
	  DrawRectangle(posX, posY, rectWidth, rectHeight, DARKGREEN); 
	  DrawRectangle(30, posY, 300, rectHeight, LIGHTGRAY); 
	  //black buttons below
	  DrawRectangle(30, 550, 80, 80, BLACK); //VERB button
	  DrawRectangle(30, 640, 80, 80, BLACK); //NOUN button
	  DrawRectangle(680, 550, 80, 80, BLACK); //ENTR button
	  DrawRectangle(680, 640, 80, 80, BLACK); //RSET button
	  EndDrawing();
	}

	CloseWindow();
	return 0;
}
