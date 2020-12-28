#include<stdio.h>
#include<stdlib.h>
#include "CC212SGL.h"
#include <windows.h>
#include <time.h>
#pragma comment(lib, "CC212SGL.lib")
 CC212SGL g;

#include "connect4.h"
#include "tictactoe.h"






int main() {

	int gameChoice = 0;
	int userGameChoice = 1;

	g.setup();

	g.setFullScreenMode();
	g.hideCursor();

	while (1) {
		g.beginDraw();
		if (gameChoice == 0)
		{
			g.setDrawingColor(COLORS::BLUE);
			g.setFontSizeAndBoldness(80, 200);
			g.drawText(210, (g.getWindowHeight() / 2 - 280), "Gameboard games");

			g.setDrawingColor(COLORS::WHITE);
			g.drawText(210, (g.getWindowHeight() / 2 - 160), "Tic Tac toe");
			g.drawText(210, (g.getWindowHeight() / 2 - 80), "Connect 4");
			if (kbhit())
			{
				if (GetAsyncKeyState(VK_UP) && userGameChoice == 2)
				{
					userGameChoice--;
				}
				else if (GetAsyncKeyState(VK_DOWN) && userGameChoice == 1)
				{
					userGameChoice++;
				}
				else if (GetAsyncKeyState(VK_SPACE))
				{
					gameChoice = userGameChoice;
				}
			}
			g.drawRectangle(200, g.getWindowHeight() / 2 - (160 / userGameChoice), 600, 80);

			g.endDraw();
		}
		else if (gameChoice == 1) {
			TicTacToe tictactoe;
			tictactoe.TICTACTOE();
		}
		else if (gameChoice == 2) {
			Connect4 c4;

			c4.connect4();
		}
		//g.endDraw();
	}
	return 0;
}