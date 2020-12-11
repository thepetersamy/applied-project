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

	int height = g.getWindowHeight(), yBoard = height / 2 - 400;
	int width = g.getWindowWidth(), xBoard = width / 2 - 400;


	while (true)
	{
		g.beginDraw();
		g.setDrawingColor(COLORS::WHITE);
		g.drawSolidRectangle(0, 0, width, height);//background
		
		g.setDrawingColor(COLORS::BLACK);
		g.setDrawingThickness(15);
		g.drawSolidRectangle(xBoard, yBoard, 800, 800); //boarder
		g.setDrawingThickness(0);

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