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
	
	  DrawRectangle(640, 30, 100, 50, LIME); //PROG 
	  
	  DrawRectangle(640, 150, 100, 50, LIME); //NOUN 
	  DrawRectangle(400, 150, 100, 50, LIME); //VERB 

          //separators
	  DrawRectangle(400, 270, 340, 5, LIME); 
	  DrawRectangle(400, 345, 340, 5, LIME); 
	  DrawRectangle(400, 425, 340, 5, LIME); 

	  //black buttons below
	  DrawRectangle(100, 550, 80, 80, BLACK); //VERB button
	  DrawRectangle(100, 640, 80, 80, BLACK); //NOUN button
	
	  DrawRectangle(190, 530, 80, 80, BLACK); // + button
	  DrawRectangle(280, 530, 80, 80, BLACK); // 7 button
	  DrawRectangle(370, 530, 80, 80, BLACK); // 8 button
	  DrawRectangle(460, 530, 80, 80, BLACK); // 9 button
	  DrawRectangle(550, 530, 80, 80, BLACK); // CLR button

	  DrawRectangle(190, 620, 80, 80, BLACK); // 1 button
	  DrawRectangle(280, 620, 80, 80, BLACK); // 4 button
	  DrawRectangle(370, 620, 80, 80, BLACK); // 5 button
	  DrawRectangle(460, 620, 80, 80, BLACK); // 6 button
	  DrawRectangle(550, 620, 80, 80, BLACK); // PRO button
	
	  DrawRectangle(190, 710, 80, 80, BLACK); // 0 button
	  DrawRectangle(280, 710, 80, 80, BLACK); // 1 button
	  DrawRectangle(370, 710, 80, 80, BLACK); // 2 button
	  DrawRectangle(460, 710, 80, 80, BLACK); // 3 button
	  DrawRectangle(550, 710, 80, 80, BLACK); // KEYREL button

	  DrawRectangle(640, 550, 80, 80, BLACK); //ENTR button
	  DrawRectangle(640, 640, 80, 80, BLACK); //RSET button
	
	  DrawText("PROG", 646, 40, 32, DARKGREEN);
	  DrawText("NOUN", 646, 160, 32, DARKGREEN);
	  DrawText("VERB", 404, 160, 32, DARKGREEN);

	  DrawText("VERB", 104, 575, 26, RAYWHITE);
	  DrawText("NOUN", 106, 665, 26, RAYWHITE);

	  DrawText("+", 218, 548, 48, RAYWHITE);
	  DrawText("7", 308, 548, 48, RAYWHITE);
	  DrawText("8", 398, 548, 48, RAYWHITE);
	  DrawText("9", 488, 548, 48, RAYWHITE);
	  DrawText("CLR", 562, 556, 30, RAYWHITE);

	  DrawText("-", 220, 638, 48, RAYWHITE);
	  DrawText("4", 308, 638, 48, RAYWHITE);
	  DrawText("5", 398, 638, 48, RAYWHITE);
	  DrawText("6", 488, 638, 48, RAYWHITE);
	  DrawText("PRO", 562, 646, 30, RAYWHITE);

	  DrawText("0", 220, 728, 48, RAYWHITE);
	  DrawText("1", 315, 728, 48, RAYWHITE);
	  DrawText("2", 400, 728, 48, RAYWHITE);
	  DrawText("3", 490, 728, 48, RAYWHITE);
	  DrawText("KEY", 565, 722, 26, RAYWHITE);
	  DrawText("REL", 565, 722 + 30, 26, RAYWHITE);

	  DrawText("ENTR", 645, 575, 26, RAYWHITE);
	  DrawText("RSET", 645, 665, 26, RAYWHITE);

	  EndDrawing();
	}

	CloseWindow();
	return 0;
}
