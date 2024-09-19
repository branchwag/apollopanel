#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int main(void) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Apollo Panel");
	SetTargetFPS(60);
	
	int frameCount = 0;

	while (!WindowShouldClose()) {
	  frameCount++;
	}

	BeginDrawing();
	ClearBackground(RAYWHITE);
	
	EndDrawing();
	CloseWindow();
	return 0;
}
