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
	int height = g.getWindowHeight(), yBoard = height / 2 - 400;
	int width = g.getWindowWidth(), xBoard = width / 2 - 400;


	while (true)
	{
		g.beginDraw();
		
		//setting color of background
		g.fillScreen(COLORS::WHITE);
		
		g.setDrawingColor(COLORS::BLACK);
		g.setDrawingThickness(15);
		g.drawSolidRectangle(xBoard, yBoard, 800, 800); //boarder of gameboard
		
		g.setDrawingThickness(0);

		//drawing whtie and black tiles
		for (int j = yBoard, count = 1; j < yBoard + 800; j = j + 100)
		{ 			
			for (int i = xBoard; i < xBoard + 800; i = i + 200) {
				g.setDrawingColor(COLORS::WHITE);
				g.drawSolidRectangle((count % 2 == 0) ? i + 100 : i, j, 100, 100);
				g.setDrawingColor(COLORS::BLACK);
				g.drawSolidRectangle((count % 2 == 0) ? i : i+100, j, 100, 100);
			}				
			++count;
		}
			
		g.endDraw();

		
	}
	getch();
}
