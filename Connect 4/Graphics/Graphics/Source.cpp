#include <stdio.h>
#include "CC212SGL.h"
#include <windows.h>

#pragma comment(lib, "CC212SGL.lib")

CC212SGL g;
void drawConnect4(int x,int y)
{
	//setting color of background
	g.fillScreen(COLORS::BLACK);

	g.setDrawingColor(COLORS::BLUE);
	g.setDrawingThickness(30);
	g.drawSolidRectangle(x, y, 700, 600); //boarder of gameboard

	g.setDrawingThickness(0);

	//drawing circles
	for (int j = y; j < y + 600; j = j + 100)
	{
		for (int i = x; i < x + 700; i = i + 100) {
			g.setDrawingColor(COLORS::WHITE);
			g.drawSolidCircle(i, j, 90);
		}
	}
	
}
int main()
{
	

	g.setup();

	g.setFullScreenMode();
	g.hideCursor();
	
	// getting height and width of screen
	int width = g.getWindowWidth(), height = g.getWindowHeight();
	int xBoard = width / 2 - 350, yBoard = height / 2 - 300; // y and x board are for calibrating the game board at the center of the screen
	int xC = xBoard, yC = yBoard-115;
	

	while (true)
	{
		g.beginDraw();
		drawConnect4(xBoard, yBoard);
		
		
		g.setDrawingColor(COLORS::BLUE);
		
		if (kbhit)
		{
			
			if (GetAsyncKeyState(VK_RIGHT) && xC < xBoard +600)
			{
				xC += 100;
			}
			else if (GetAsyncKeyState(VK_LEFT) && xC > xBoard)
			{
				xC -= 100;			
			}				
		}
		g.drawSolidCircle(xC, yC, 90);
		g.endDraw();
		Sleep(100);
	}
	getch();
}
