#include <stdio.h>
#include "CC212SGL.h"
#include <windows.h>

#pragma comment(lib, "CC212SGL.lib")

CC212SGL g;
void drawTicTacToe(int xStartingBoardCoordinates, int yStartingBoardCoordinates) {

	//setting color of background
	g.fillScreen(COLORS::BLACK);

	g.setDrawingColor(COLORS::BLUE);
	g.setDrawingThickness(30);
	g.drawSolidRectangle(xStartingBoardCoordinates, yStartingBoardCoordinates, 700, 600); //boarder of gameboard

	g.setDrawingThickness(0);

	////drawing circles
	//for (int i = xStartingBoardCoordinates; i < xStartingBoardCoordinates + WIDTH; i = i + 100) {
	//	for (int j = yStartingBoardCoordinates; j < yStartingBoardCoordinates + HEIGHT; j = j + 100){

	//	
	//		g.setDrawingColor(COLORS::WHITE);
	//		g.drawSolidCircle(i, j, 90);
	//	}
	//}
	for (int column = 0, j = yStartingBoardCoordinates; (column < ROWS) && j < j + 600; column++, j += 100) {
		for (int row = 0, i = xStartingBoardCoordinates; (row < COLS) && i < i + 700; row++, i += 100) {

			g.setDrawingColor(COLORS::WHITE);
			g.drawSolidCircle(i, j, 90);
		}
	}


}

int main()
{
	g.setup(1);

	g.setFullScreenMode();
	g.hideCursor();

	int screenWidth = g.getWindowWidth();
	int screenHeight = g.getWindowHeight();// getting height and width of screen

	int xBoard = screenWidth / 2 - HEIGHT / 2;
	int yBoard = screenHeight / 2 - WIDTH / 2; // y and x board are for calibrating the game board at the center of the screen


	int xC = xBoard;
	int yC = yBoard - 115;

	int userInput = 0; //to get user input

	while (true)
	{
		g.beginDraw();
		if (kbhit)
		{

			if (GetAsyncKeyState(VK_RIGHT) && xC < xBoard + 600)
			{
				xC += 100;
				userInput++;
			}
			else if (GetAsyncKeyState(VK_LEFT) && xC > xBoard)
			{
				xC -= 100;
				userInput--;
			}
			else if (GetAsyncKeyState(27))
				break;
		}

		g.endDraw();
		Sleep(150);
	}
}
