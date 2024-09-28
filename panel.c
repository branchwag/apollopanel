#include "raylib.h"
#include <string.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

typedef struct {
    Rectangle rect;
    Color color;
    const char* text;
    int fontSize;
} Button;

#define NUM_BUTTONS 19

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

        Font monogram = LoadFont("monogram.ttf");
	Vector2 position1 = {660, 38};
	Vector2 position2 = {658, 158};
	Vector2 position3 = {418, 158};
	//mebbe int button var here since the black btns are always 80x80

	Rectangle verbButton = {100, 550, 80, 80};
	Rectangle nounButton = {100, 640, 80, 80};
	Rectangle plusButton = {190, 530, 80, 80};
	Rectangle sevenButton = {280, 530, 80, 80};
	Rectangle eightButton = {370, 530, 80, 80};
	Rectangle nineButton = {460, 530, 80, 80};
	Rectangle clearButton = {550, 530, 80, 80};
	Rectangle minusButton = {190, 620, 80, 80};
	Rectangle fourButton = {280, 620, 80, 80};
	Rectangle fiveButton = {370, 620, 80, 80};
	Rectangle sixButton = {460, 620, 80, 80};
	Rectangle proButton = {550, 620, 80, 80};
	Rectangle zeroButton = {190, 710, 80, 80};
	Rectangle oneButton = {280, 710, 80, 80};
	Rectangle twoButton = {370, 710, 80, 80};
	Rectangle threeButton = {460, 710, 80, 80};
	Rectangle keyrelButton = {550, 710, 80, 80};
	Rectangle entrButton = {640, 550, 80, 80};
        Rectangle resetButton = {640, 640, 80, 80};

    //rect, color, text, fontsize
    Button buttons[NUM_BUTTONS] = {
        {verbButton, BLACK, "VERB", 26},
        {nounButton, BLACK, "NOUN", 26},
        {plusButton, BLACK, "+", 48},
        {sevenButton, BLACK, "7", 48},
        {eightButton, BLACK, "8", 48},
        {nineButton, BLACK, "9", 48},
        {clearButton, BLACK, "CLR", 30},
        {minusButton, BLACK, "-", 48},
        {fourButton, BLACK, "4", 48},
        {fiveButton, BLACK, "5", 48},
        {sixButton, BLACK, "6", 48},
        {proButton, BLACK, "PRO", 30},
        {zeroButton, BLACK, "0", 48},
        {oneButton, BLACK, "1", 48},
        {twoButton, BLACK, "2", 48},
        {threeButton, BLACK, "3", 48},
        {keyrelButton, BLACK, "KEY\nREL", 26},
        {entrButton, BLACK, "ENTR", 26},
        {resetButton, BLACK, "RSET", 26}
    };

    float buttonTimers[NUM_BUTTONS] = {0};
    const float BUTTON_RESET_TIME = 0.5f;

    char verbNumber[3] = "";
    char progNumber[3] = "00";
    char nounNumber[3] = "";
    char lineOneNumber[] = "";
    char lineTwoNumber[] = "";
    char lineThreeNumber[] = "";

    bool verbMode = false;
    int verbDigitCount = 0;

	while (!WindowShouldClose()) {
	  frameCount++;
	  float deltaTime = GetFrameTime();
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
	  DrawRectangle(400, 425, 340, 5, LIME); 	  \
	  
	  DrawTextEx(monogram, "PROG", position1, 32, 1, DARKGREEN);
	  DrawTextEx(monogram, "NOUN", position2, 32, 1, DARKGREEN);
	  DrawTextEx(monogram, "VERB", position3, 32, 1, DARKGREEN);

	  //PROG number
	  DrawText(progNumber, 644, 76, 86, LIME);
	  //VERB number
	  DrawText(verbNumber, 402, 196, 86, LIME);
	  //NOUN number
	  DrawText(nounNumber, 644, 196, 86, LIME);

	  DrawText("+", 380, 300, 42, LIME);
	  DrawText("+", 380, 380, 42, LIME);
	  DrawText("+", 380, 460, 42, LIME);

	  DrawText(lineOneNumber, 566, 271, 86, LIME);
	  DrawText(lineTwoNumber, 590, 348, 86, LIME);
	  DrawText(lineThreeNumber, 490, 428, 86, LIME);

      // Handle button presses and draw buttons
        for (int i = 0; i < NUM_BUTTONS; i++) {
            if (buttonTimers[i] > 0) {
                buttonTimers[i] -= deltaTime;
                if (buttonTimers[i] <= 0) {
                    buttons[i].color = BLACK;
                }
            }

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                if (CheckCollisionPointRec(mousePos, buttons[i].rect)) {
                    buttons[i].color = RED;
                    buttonTimers[i] = BUTTON_RESET_TIME;

		    //verb btn press
		    if(strcmp(buttons[i].text, "VERB") == 0) {
			verbMode = true;
			verbDigitCount = 0;
			memset(verbNumber, 0, sizeof(verbNumber));
		    }

		    else if (verbMode && verbDigitCount < 2 && buttons[i].text[0] >= '0' && buttons[i].text[0] <= '9') {
			verbNumber[verbDigitCount] = buttons[i].text[0];
			verbDigitCount++;
			if (verbDigitCount == 2) {
			    verbMode = false;
			}
		    }
                }
            }

            DrawRectangleRec(buttons[i].rect, buttons[i].color);
            DrawText(buttons[i].text, 
                     buttons[i].rect.x + buttons[i].rect.width/2 - MeasureText(buttons[i].text, buttons[i].fontSize)/2, 
                     buttons[i].rect.y + buttons[i].rect.height/2 - buttons[i].fontSize/2, 
                     buttons[i].fontSize, 
                     RAYWHITE);
        }

	//updated verb number
	DrawText(verbNumber, 402, 196, 86, LIME);

        EndDrawing();
    }

    CloseWindow();
	return 0;
}
