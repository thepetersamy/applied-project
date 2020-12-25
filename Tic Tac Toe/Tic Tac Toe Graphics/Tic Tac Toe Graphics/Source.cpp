#include <stdio.h>
#include "CC212SGL.h"
#include <windows.h>

#pragma comment(lib, "CC212SGL.lib")

CC212SGL g;

#define SIDE 600
#define SIZE 3

void createGameBoard(int gameBoard[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			gameBoard[i][j] = 0;
		}
	}
}

void drawTicTacToe(int gameBoard[SIZE][SIZE],int xStartingBoardCoordinates, int yStartingBoardCoordinates,int shape[]) {

	//setting color of background
	g.fillScreen(COLORS::BLACK);

	g.setDrawingColor(COLORS::BLUE);
	g.setDrawingThickness(15);
	g.drawSolidRectangle(xStartingBoardCoordinates, yStartingBoardCoordinates, SIDE-10, SIDE-10); //boarder of gameboard
	g.setDrawingThickness(0);

	for (int column = 0, j = yStartingBoardCoordinates; (column < SIZE); column++, j += 200) {
		for (int row = 0, i = xStartingBoardCoordinates; (row < SIZE); row++, i += 200) {
			if (gameBoard[row][column] == 0) {
				g.setDrawingColor(COLORS::WHITE);
				g.drawSolidRectangle(i, j, 190, 190);
			}
			else if (gameBoard[row][column] == 1) {
				g.setDrawingColor(COLORS::WHITE);
				g.drawSolidRectangle(i, j, 190, 190);
				g.drawImage(shape[0], i, j, RGB(47, 255, 0));
			}
			else if (gameBoard[row][column] == 2) {
				g.setDrawingColor(COLORS::WHITE);
				g.drawSolidRectangle(i, j, 190, 190);
				g.drawImage(shape[1], i, j, RGB(47, 255, 0));
			}
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
	int yC = yBoard;

	int yUserInput = 0; //to get user input
	int xUserInput = 0;

	int gameBoard[SIZE][SIZE];

	int shape[2];//X & O
	shape[0] = g.loadImage("x.png");
	shape[1] = g.loadImage("o.png");

	createGameBoard(gameBoard);

	while (true)
	{
		g.beginDraw();

		drawTicTacToe(gameBoard, xBoard, yBoard, shape);

		if (kbhit) {
			if (GetAsyncKeyState(VK_SPACE)) {}

			else if (GetAsyncKeyState(VK_RIGHT) && xC < xBoard + SIDE-200)
			{
				xC += 200;
				xUserInput++;
			}
			else if (GetAsyncKeyState(VK_LEFT) && xC > xBoard)
			{
				xC -= 200;
				xUserInput--;
			}
			else if (GetAsyncKeyState(VK_DOWN) && yC < yBoard + SIDE-200)
			{
				yC += 200;
				yUserInput++;
			}
			else if (GetAsyncKeyState(VK_UP) && yC > yBoard)
			{
				yC -= 200;
				yUserInput--;
			}
		}

		else if (GetAsyncKeyState(27))
			break;

		g.setDrawingColor(COLORS::RED);
		g.setDrawingThickness(5);
		g.drawRectangle(xC, yC, 190,190);
		

		g.endDraw();
		Sleep(150);
	}
}
