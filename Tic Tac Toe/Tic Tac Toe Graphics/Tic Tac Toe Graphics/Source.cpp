#include <stdio.h>
#include "CC212SGL.h"
#include <windows.h>

#pragma comment(lib, "CC212SGL.lib")

CC212SGL g;

#define SIDE 600
#define ROWS 3
#define COLS 3
void drawTicTacToe(int xStartingBoardCoordinates, int yStartingBoardCoordinates) {

	//setting color of background
	g.fillScreen(COLORS::BLACK);

	g.setDrawingColor(COLORS::BLUE);
	g.setDrawingThickness(0);
	g.drawSolidRectangle(xStartingBoardCoordinates, yStartingBoardCoordinates, SIDE-10, SIDE-10); //boarder of gameboard

	for (int column = 0, j = yStartingBoardCoordinates; (column < ROWS); column++, j += 200) {
		for (int row = 0, i = xStartingBoardCoordinates; (row < COLS); row++, i += 200) {

			g.setDrawingColor(COLORS::WHITE);
			g.drawSolidRectangle(i, j, 190,190);
		}
	}


}

int main()
{
	g.setup();

	g.setFullScreenMode();
	g.hideCursor();


	int screenWidth = g.getWindowWidth();
	int screenHeight = g.getWindowHeight();// getting height and width of screen

	int xBoard = screenWidth / 2 - SIDE / 2;
	int yBoard = screenHeight / 2 - SIDE / 2; // y and x board are for calibrating the game board at the center of the screen


	int xC = xBoard;
	int yC = yBoard - 115;

	int userInput = 0; //to get user input

	while (true)
	{
		g.beginDraw();

		drawTicTacToe(xBoard,yBoard);
		
		g.endDraw();
		Sleep(150);
	}
}
