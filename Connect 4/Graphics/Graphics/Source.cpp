#include <stdio.h>
#include "CC212SGL.h"
#include <windows.h>

#pragma comment(lib, "CC212SGL.lib")

int main()
{
	CC212SGL g;

	g.setup();


	g.setFullScreenMode();
	g.hideCursor();

	// getting height and width of screen
	// y and x board are for calibrating the game board at the center of the screen
	int height = g.getWindowHeight(), yBoard = height / 2 - 437.5;
	int width = g.getWindowWidth(), xBoard = width / 2 - 512.5;


	while (true)
	{
		g.beginDraw();

		//setting color of background
		g.fillScreen(COLORS::SKYBLUE);
		
		g.setDrawingColor(COLORS::BLUE);
		g.setDrawingThickness(50);
		g.drawSolidRectangle(xBoard, yBoard, 1025, 875); //boarder of gameboard
		
		g.setDrawingThickness(0);

		//drawing circles
		for (int j = yBoard; j < yBoard + 800; j = j + 150)
		{
			for (int i = xBoard; i < xBoard + 1000; i = i + 150) {
				g.setDrawingColor(COLORS::WHITE);
				g.drawSolidCircle(i, j, 125);
			}
		}
			
		g.endDraw();

		
	}
	getch();
}
