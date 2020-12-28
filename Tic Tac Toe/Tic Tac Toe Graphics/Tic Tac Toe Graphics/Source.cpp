#include <stdio.h>
#include "CC212SGL.h"
#include <windows.h>
#include<time.h>

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


int switchPlayer(int playerTurn) {
	return playerTurn == 1 ? 2 : 1;
}



bool isOccupied(int gameBoard[SIZE][SIZE], int x, int y) {
	return gameBoard[x][y] == 0 ? 0 : 1;
}


bool coordinatesExist(int x, int y) {
	return ((x >= 0 && x < 3) && (y >= 0 && y < 3));
}


void placeToken(int gameBoard[SIZE][SIZE], int playersTurn, int x, int y) {
	gameBoard[x][y] = playersTurn;
}

<<<<<<< HEAD

bool isBoardFull(int gameBoard[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (gameBoard[i][j] == 0)
				return 0;
		}
	}
	return 1;

bool isBoardFull(int gameBoard[SIZE][SIZE], int playersTurn, int x, int y) {
=======
bool isBoardFull(int gameBoard[SIZE][SIZE]) {
>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (gameBoard[i][j] == 0)
				return 0;
		}
	}
<<<<<<< HEAD
	return 0;
>>>>>>> 20cc8fe5fddc419d74ffc95b94ba14937b9c3845
=======
	return 1;
>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9
}


bool playerWonHorizontally(int gameBoard[SIZE][SIZE], int playersTurn) {
	int counter = 0;
	for (int row = 0; row < SIZE; row++) {
		for (int column = 0; column < SIZE; column++) {

			if (gameBoard[row][column] == playersTurn) {
				counter++;
				if (counter == 3) {
					return 1;
				}
			}
			else {
				counter = 0;
			}
		}
		counter = 0;
	}

	return 0;
}


bool playerWonVertically(int gameBoard[SIZE][SIZE], int playersTurn) {
	int counter = 0;
	for (int column = 0; column < SIZE; column++) {
		for (int row = 0; row < SIZE; row++) {

			if (gameBoard[row][column] == playersTurn) {
				counter++;
				if (counter == 3) {
					return 1;
				}
			}
			else {
				counter = 0;
			}
		}
		counter = 0;
	}
	return 0;
}


bool playerWondiagonally(int gameBoard[SIZE][SIZE], int playersTurn) {

	int counter = 0;
	for (int i = 0; i < SIZE; i++) {
		if (gameBoard[i][i] == playersTurn) {
			counter++;
			if (counter == 3) {
				return 1;
			}
		}
		else {
			counter = 0;
		}
	}
	counter = 0;
	for (int i = 0; i < SIZE; i++) {
		if (gameBoard[i][SIZE - i - 1] == playersTurn) {
			counter++;
			if (counter == 3) {
				return 1;
			}
		}
		else {
			counter = 0;
		}
	}
	return 0;
}


<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9
//void twoPlayerGame(int gameBoard[SIZE][SIZE]) {
//
//
//	int gameNotOver = 1;
//
//	int playersTurn = 1;
//
//	createGameBoard(gameBoard);
//
//	while (gameNotOver) {
//		bool played = 0;
//
//		int x, y;
//
//		// user input for column
//		printf("**PLAYER %d**\n", playersTurn);
//		printf("plaese enter the (x,y) coordinates you wish to place the token in:");
//		scanf("%d%d", &x, &y);
//		printf("\n\n");
//
//
//		if (isBoardFull) {
//			if (coordinatesExist(x, y)) {
//
//				if (!isOccupied(gameBoard, x, y)) {
//
//					placeToken(gameBoard, playersTurn, x, y);
//					if (playerWonVertically(gameBoard, playersTurn) || playerWonHorizontally(gameBoard, playersTurn) || playerWondiagonally(gameBoard, playersTurn)) {
//
//						printf("player %d WON!!!\n", playersTurn);
//						break;
//					}
//
//				}
//				else {
//					printf("block is occuipied please choose another one\n");
//					continue;
//				}
//			}
//			else {
//				printf("coordinates you entered does not exist\n");
//				continue;
//			}
//		}
//		else {
//			printf("board is full, its a tie!\n");
//			gameNotOver = 0;
//			break;
//		}
//		playersTurn = switchPlayer(playersTurn);
//	}
//
//}
<<<<<<< HEAD

//bool playerAboutToWinHorizontally(int gameBoard[SIZE][SIZE], int* rowNumber) {
//	// is real player about to win horizontally?
//	int counter = 0;
//	for (int column = 0; column < SIZE; column++) {
//		for (int row = 0; row < SIZE; row++) {
//			if (gameBoard[row][column] == 2) {
//				counter++;
//
//				if (counter == 2) {
//					rowNumber = &row;
//					return 1;
//				}
//			}
//			else {
//				counter = 0;
//			}
//		}
//	}
//	return 0;
//}
//
//bool playerAboutToWinvertically(int gameBoard[SIZE][SIZE]) {
//	// is real player about to win horizontally?
//	int counter = 0;
//	for (int row = 0; row < SIZE; row++) {
//		for (int column = 0; column < SIZE; column++) {
//			if (gameBoard[row][column] == 2) {
//				counter++;
//
//				if (counter == 2) {
//					return 1;
//				}
//			}
//			else {
//				counter = 0;
//			}
//		}
//	}
//	return 0;
//}
=======
void twoPlayerGame(int gameBoard[SIZE][SIZE]) {


	int gameNotOver = 1;

	int playersTurn = 1;

	createGameBoard(gameBoard);

	while (gameNotOver) {
		bool played = 0;

		int x, y;

		// user input for column
		printf("**PLAYER %d**\n", playersTurn);
		printf("plaese enter the (x,y) coordinates you wish to place the token in:");
		scanf("%d%d", &x, &y);
		printf("\n\n");


		if (isBoardFull) {
			if (coordinatesExist(x, y)) {

				if (!isOccupied(gameBoard, x, y)) {

					placeToken(gameBoard, playersTurn, x, y);
					if (playerWonVertically(gameBoard, playersTurn) || playerWonHorizontally(gameBoard, playersTurn) || playerWondiagonally(gameBoard, playersTurn)) {

						printf("player %d WON!!!\n", playersTurn);
						break;
					}

				}
				else {
					printf("block is occuipied please choose another one\n");
					continue;
				}
			}
			else {
				printf("coordinates you entered does not exist\n");
				continue;
			}
		}
		else {
			printf("board is full, its a tie!\n");
			gameNotOver = 0;
			break;
		}
		playersTurn = switchPlayer(playersTurn);
	}

}

bool playerAboutToWinHorizontally(int gameBoard[SIZE][SIZE], int* rowNumber) {
	// is real player about to win horizontally?
	int counter = 0;
	for (int column = 0; column < SIZE; column++) {
		for (int row = 0; row < SIZE; row++) {
			if (gameBoard[row][column] == 2) {
				counter++;

				if (counter == 2) {
					rowNumber = &row;
					return 1;
				}
			}
			else {
				counter = 0;
			}
		}
	}
	return 0;
}

bool playerAboutToWinvertically(int gameBoard[SIZE][SIZE]) {
	// is real player about to win horizontally?
	int counter = 0;
	for (int row = 0; row < SIZE; row++) {
		for (int column = 0; column < SIZE; column++) {
			if (gameBoard[row][column] == 2) {
				counter++;

				if (counter == 2) {
					return 1;
				}
			}
			else {
				counter = 0;
			}
		}
	}
	return 0;
}
>>>>>>> 20cc8fe5fddc419d74ffc95b94ba14937b9c3845
=======

//bool playerAboutToWinHorizontally(int gameBoard[SIZE][SIZE], int* rowNumber) {
//	// is real player about to win horizontally?
//	int counter = 0;
//	for (int column = 0; column < SIZE; column++) {
//		for (int row = 0; row < SIZE; row++) {
//			if (gameBoard[row][column] == 2) {
//				counter++;
//
//				if (counter == 2) {
//					rowNumber = &row;
//					return 1;
//				}
//			}
//			else {
//				counter = 0;
//			}
//		}
//	}
//	return 0;
//}
//
//bool playerAboutToWinvertically(int gameBoard[SIZE][SIZE]) {
//	// is real player about to win horizontally?
//	int counter = 0;
//	for (int row = 0; row < SIZE; row++) {
//		for (int column = 0; column < SIZE; column++) {
//			if (gameBoard[row][column] == 2) {
//				counter++;
//
//				if (counter == 2) {
//					return 1;
//				}
//			}
//			else {
//				counter = 0;
//			}
//		}
//	}
//	return 0;
//}
>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9

//void computersPlay(int gameBoard[SIZE][SIZE], int *x, int *y) {
//	int rowNumber;
//	if (playerAboutToWinHorizontally(gameBoard, &rowNumber)) {
//
//	}
//
//
//}



void generateRandomCordinates(int gameBoard[SIZE][SIZE], int* x, int* y) {
	time_t t;
	srand((unsigned)time(&t));
	//printf("%d\n", rand() % 3);

	while (isOccupied(gameBoard, *x = rand() % 3, *y = rand() % 3));
}

//void onePlayerGame(int gameBoard[SIZE][SIZE]) {
//
//
//
//	int gameNotOver = 1;
//
//	int playersTurn = 1;
//
//	createGameBoard(gameBoard);
//	printGameBoard(gameBoard);
//
//	while (gameNotOver) {
//		bool played = 0;
//
//		int x, y;
//
//
//		if (playersTurn == 1) {
//			// user input for column
//			printf("**PLAYER %d**\n", playersTurn);
//			printf("plaese enter the (x,y) coordinates you wish to place the token at:");
//
//			scanf("%d%d", &x, &y);
//			printf("\n\n");
//
//		}
//		else if (playersTurn == 2) {
//			printf("**PLAYER %d**\n", playersTurn);
//			generateRandomCordinates(gameBoard, &x, &y);
//			printf("computer played at (%d,%d)\n\n", x , y );
//		}
//		if (isBoardFull) {
//			if (coordinatesExist(x, y)) {
//
//				if (!isOccupied(gameBoard, x, y)) {
//
//					placeToken(gameBoard, playersTurn, x, y);
//					printGameBoard(gameBoard);
//					if (playerWonVertically(gameBoard, playersTurn) || playerWonHorizontally(gameBoard, playersTurn) || playerWondiagonally(gameBoard, playersTurn)) {
//
//						if (playersTurn == 1) {
//							printf("YOU WON!!!");
//						}
//						else {
//							printf("COMPUTER WON!!!!");
//						}
//						break;
//					}
//
//				}
//				else {
//					printf("block is occuipied please choose another one\n");
//					continue;
//				}
//			}
//			else {
//				printf("coordinates you entered does not exist\n");
//				continue;
//			}
//		}
//		else {
//			printf("board is full, its a tie!\n");
//			gameNotOver = 0;
//			break;
//		}
//		playersTurn = switchPlayer(playersTurn);
//	}
//
//
//}
//

<<<<<<< HEAD
<<<<<<< HEAD
void drawTicTacToe(int gameBoard[SIZE][SIZE], int xStartingBoardCoordinates, int yStartingBoardCoordinates, int shape[]) {
=======
void drawTicTacToe(int gameBoard[SIZE][SIZE],int xStartingBoardCoordinates, int yStartingBoardCoordinates,int shape[]) {
>>>>>>> 20cc8fe5fddc419d74ffc95b94ba14937b9c3845
=======
void drawTicTacToe(int gameBoard[SIZE][SIZE], int xStartingBoardCoordinates, int yStartingBoardCoordinates, int shape[]) {
>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9

	//setting color of background
	g.fillScreen(COLORS::BLACK);

	g.setDrawingColor(COLORS::BLUE);
	g.setDrawingThickness(15);
	g.drawSolidRectangle(xStartingBoardCoordinates, yStartingBoardCoordinates, SIDE - 10, SIDE - 10); //boarder of gameboard
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

void saveGame(int gameBoard[SIZE][SIZE], const char* fileName, int playersTurn) {

	FILE* file = fopen(fileName, "wb+");


	// writing gameboard to file
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			char current[2];
			sprintf(current, "%d", gameBoard[i][j]);
			fputs(current, file);
		}
	}
	//writing playersTurn to file
	char turn[2];
	sprintf(turn, "%d", playersTurn);
	fputs(turn, file);

	printf("[Game Saved]");

	fclose(file);

}


bool fileExists(const char* fileName) {
	FILE* file;
	if ((file = fopen(fileName, "r"))) {
		fclose(file);
		return 1;
	}
	return 0;
}

// load game function returns game board as an arg and returns the playersTurn noramally
int loadGame(int gameBoard[SIZE][SIZE], const char* fileName) {

	FILE* file = fopen(fileName, "rb");
	int current;
	int arr[SIZE * SIZE + 1];
	int x = 0;
	int playersTurn;

	// reading gameboard into a 1D array
	// the +1 is for the palayersTurn
	for (int i = 0; i < SIZE * SIZE + 1; i++) {
		fscanf(file, "%c", &current);
		arr[i] = current;
	}


	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			gameBoard[i][j] = char(arr[x++] - '0');
		}
	}

	fscanf(file, "%c", &current);
	playersTurn = char(current - '0');

	fclose(file);
	printf("[Game Loaded]\n");
	printf("playersTurn::%d\n", playersTurn);

	return playersTurn;


}

<<<<<<< HEAD
=======
void msg(int width, int height, const char* txt)
{

	g.setDrawingColor(COLORS::LIME);
	g.drawSolidRectangle(width - (34 * strlen(txt)) / 2, height - 80, 34 * strlen(txt), 80);
	g.setDrawingColor(COLORS::BLACK);
	g.setFontSizeAndBoldness(80, 200);
	g.drawText(width - (34 * strlen(txt)) / 2, height - 80, txt);
	g.endDraw();
	Sleep(1500);
}

>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9
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
<<<<<<< HEAD
<<<<<<< HEAD
	int playerChoice = 0;
=======
	int playerChoice=0;
>>>>>>> 20cc8fe5fddc419d74ffc95b94ba14937b9c3845
=======
	int playerChoice = 0;
>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9
	int gameNotOver = 1;

	int playersTurn = 1;
	int singleMultiChoice = 1;
	int gameStarted = 0; //to avoid starting after menu
	int computerTurn = 0; //to activate computer turn

	createGameBoard(gameBoard);

	while (true)
	{
		g.beginDraw();
		if (playerChoice == 0)
		{
			g.setDrawingColor(COLORS::BLUE);
			g.setFontSizeAndBoldness(80, 200);
			g.drawText(210, screenHeight / 2 - 280, "Connect 4");

			g.setDrawingColor(COLORS::WHITE);
			g.drawText(210, screenHeight / 2 - 160, "Singleplayer");
			g.drawText(210, screenHeight / 2 - 80, "Multiplayer");
			if (kbhit())
			{
				if (GetAsyncKeyState(VK_UP) && singleMultiChoice == 2)
				{
					singleMultiChoice--;
				}
				else if (GetAsyncKeyState(VK_DOWN) && singleMultiChoice == 1)
				{
					singleMultiChoice++;
				}
				else if (GetAsyncKeyState(VK_SPACE))
				{
					playerChoice = singleMultiChoice;
				}
			}
			g.drawRectangle(200, screenHeight / 2 - (160 / singleMultiChoice), 600, 80);

			g.endDraw();
		}
		else {
<<<<<<< HEAD

			drawTicTacToe(gameBoard, xBoard, yBoard, shape);

			if ((kbhit && gameStarted == 1) || computerTurn == 1) {
				if (GetAsyncKeyState(VK_SPACE) || computerTurn == 1) {
					bool played = 0;

					int x, y;

					// user input for column


					if (playerChoice == 2) {
						// user input for column
						x = xUserInput;
						y = yUserInput;
					}
					else if (playerChoice == 1) {
						if (playersTurn == 1) {
							computerTurn = 1;

							x = xUserInput;
							y = yUserInput;
						}
						else if (playersTurn == 2) {
							generateRandomCordinates(gameBoard, &x, &y);
							computerTurn = 0;
						}
					}



					if (!isBoardFull(gameBoard)) {
						if (coordinatesExist(x, y)) {

							if (!isOccupied(gameBoard, x, y)) {

								placeToken(gameBoard, playersTurn, x, y);
								if (playerWonVertically(gameBoard, playersTurn) || playerWonHorizontally(gameBoard, playersTurn) || playerWondiagonally(gameBoard, playersTurn)) {
									if (playerChoice == 1) {
										if (playersTurn == 1) {
											drawTicTacToe(gameBoard, xBoard, yBoard, shape);

											g.setDrawingColor(COLORS::LIME);
											g.drawSolidRectangle(screenWidth / 2 - 280, screenHeight / 2 - 80, 510, 80);
											g.setDrawingColor(COLORS::BLACK);
											g.setFontSizeAndBoldness(80, 200);
											g.drawText(screenWidth / 2 - 280, screenHeight / 2 - 80, "YOU WON!!!");
											g.endDraw();

										}
										else if (playersTurn == 2) {
											drawTicTacToe(gameBoard, xBoard, yBoard, shape);

											g.setDrawingColor(COLORS::LIME);
											g.drawSolidRectangle(screenWidth / 2 - 280, screenHeight / 2 - 80, 510, 80);
											g.setDrawingColor(COLORS::BLACK);
											g.setFontSizeAndBoldness(80, 200);
											g.drawText(screenWidth / 2 - 280, screenHeight / 2 - 80, "YOU LOSE!!!");
											g.endDraw();
										}
									}
									else if (playerChoice == 2) {
										drawTicTacToe(gameBoard, xBoard, yBoard, shape);

										g.setDrawingColor(COLORS::LIME);
										g.drawSolidRectangle(screenWidth / 2 - 280, screenHeight / 2 - 80, 510, 80);
										g.setDrawingColor(COLORS::BLACK);
										g.setFontSizeAndBoldness(80, 200);
										char tmp[50];
										sprintf(tmp, "Player %d WON!!!", playersTurn);
										g.drawText(screenWidth / 2 - 280, screenHeight / 2 - 80, tmp);
										g.endDraw();

=======

			drawTicTacToe(gameBoard, xBoard, yBoard, shape);

			if ((kbhit && gameStarted == 1) || computerTurn == 1) {
				if (GetAsyncKeyState(VK_SPACE) || computerTurn == 1) {
					bool played = 0;

					int x, y;

					// user input for column


					if (playerChoice == 2) {
						// user input for column
						x = xUserInput;
						y = yUserInput;
					}
					else if (playerChoice == 1) {
						if (playersTurn == 1) {
							computerTurn = 1;

							x = xUserInput;
							y = yUserInput;
						}
						else if (playersTurn == 2) {
							generateRandomCordinates(gameBoard, &x, &y);
							computerTurn = 0;
						}
					}



					if (!isBoardFull(gameBoard)) {
						if (coordinatesExist(x, y)) {

							if (!isOccupied(gameBoard, x, y)) {

								placeToken(gameBoard, playersTurn, x, y);
								if (playerWonVertically(gameBoard, playersTurn) || playerWonHorizontally(gameBoard, playersTurn) || playerWondiagonally(gameBoard, playersTurn)) {
									if (playerChoice == 1) {
										if (playersTurn == 1) {
											drawTicTacToe(gameBoard, xBoard, yBoard, shape);
											msg(screenWidth / 2, screenHeight / 2, "YOU WIN!!!");


										}
										else if (playersTurn == 2) {
											drawTicTacToe(gameBoard, xBoard, yBoard, shape);
											msg(screenWidth / 2, screenHeight / 2, "YOU LOSE!!!");
										}
									}
									else if (playerChoice == 2) {
										drawTicTacToe(gameBoard, xBoard, yBoard, shape);
										char tmp[50];
										sprintf(tmp, "Player %d WON!!!", playersTurn);
										msg(screenWidth / 2, screenHeight / 2, tmp);

>>>>>>> 20cc8fe5fddc419d74ffc95b94ba14937b9c3845
									}
									break;
								}




							}
							else {
<<<<<<< HEAD
								g.setDrawingColor(COLORS::LIME);
								g.drawSolidRectangle(screenWidth / 2 - 550, screenHeight / 2 - 80, 1410, 80);
								g.setDrawingColor(COLORS::BLACK);
								g.setFontSizeAndBoldness(80, 200);
								g.drawText(screenWidth / 2 - 550, screenHeight / 2 - 80, "block is occuipied please choose another one");
								g.endDraw();
								Sleep(1500);
<<<<<<< HEAD
								computerTurn = 0;
=======

>>>>>>> 20cc8fe5fddc419d74ffc95b94ba14937b9c3845
=======
								drawTicTacToe(gameBoard, xBoard, yBoard, shape);
								msg(screenWidth / 2, screenHeight / 2, "block is occuipied please choose another one");

								computerTurn = 0;
>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9
								continue;
							}
						}
						else {
<<<<<<< HEAD
							g.setDrawingColor(COLORS::LIME);
							g.drawSolidRectangle(screenWidth / 2 - 550, screenHeight / 2 - 80, 1300, 80);
							g.setDrawingColor(COLORS::BLACK);
							g.setFontSizeAndBoldness(80, 200);
							g.drawText(screenWidth / 2 - 550, screenHeight / 2 - 80, "coordinates you entered does not exist");
							g.endDraw();
							Sleep(1500);
<<<<<<< HEAD
							computerTurn = 0;
=======
>>>>>>> 20cc8fe5fddc419d74ffc95b94ba14937b9c3845
=======
							drawTicTacToe(gameBoard, xBoard, yBoard, shape);
							msg(screenWidth / 2, screenHeight / 2, "coordinates you entered does not exist");
							computerTurn = 0;
>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9
							continue;
						}
					}
					else {
						drawTicTacToe(gameBoard, xBoard, yBoard, shape);
						msg(screenWidth / 2, screenHeight / 2, "board is full, its a tie!");

						gameNotOver = 0;
						break;
					}
					playersTurn = switchPlayer(playersTurn);
				}


				else if (GetAsyncKeyState(VK_RIGHT) && xC < xBoard + SIDE - 200)
				{
					xC += 200;
					xUserInput++;
				}
				else if (GetAsyncKeyState(VK_LEFT) && xC > xBoard)
				{
					xC -= 200;
					xUserInput--;
				}
				else if (GetAsyncKeyState(VK_DOWN) && yC < yBoard + SIDE - 200)
				{
					yC += 200;
					yUserInput++;
				}
				else if (GetAsyncKeyState(VK_UP) && yC > yBoard)
				{
					yC -= 200;
					yUserInput--;
				}
<<<<<<< HEAD
<<<<<<< HEAD
				else if (GetAsyncKeyState('S')) {
					saveGame(gameBoard, "xo", playersTurn);
					drawTicTacToe(gameBoard, xBoard, yBoard, shape);
					g.setDrawingColor(COLORS::LIME);
					g.drawSolidRectangle(screenWidth / 2 - 550, screenHeight / 2 - 80, 1300, 80);
					g.setDrawingColor(COLORS::BLACK);
					g.setFontSizeAndBoldness(80, 200);
					g.drawText(screenWidth / 2 - 550, screenHeight / 2 - 80, "Game saved successfully!");
					g.endDraw();
					Sleep(1500);
=======
				else if (GetAsyncKeyState('S')) {
					saveGame(gameBoard, "xo", playersTurn);
					drawTicTacToe(gameBoard, xBoard, yBoard, shape);

					msg(screenWidth / 2, screenHeight / 2, "Game saved successfully!");
					computerTurn = 0;
>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9
				}
				else if (GetAsyncKeyState('L')) {

					if (fileExists("xo")) {
						playersTurn = loadGame(gameBoard, "xo");
						drawTicTacToe(gameBoard, xBoard, yBoard, shape);
<<<<<<< HEAD
						g.setDrawingColor(COLORS::LIME);
						g.drawSolidRectangle(screenWidth / 2 - 550, screenHeight / 2 - 80, 1300, 80);
						g.setDrawingColor(COLORS::BLACK);
						g.setFontSizeAndBoldness(80, 200);
						g.drawText(screenWidth / 2 - 550, screenHeight / 2 - 80, "Game loaded successfully!");
						g.endDraw();
						Sleep(1500);
					}

					else {
						g.setDrawingColor(COLORS::LIME);
						g.drawSolidRectangle(screenWidth / 2 - 550, screenHeight / 2 - 80, 1300, 80);
						g.setDrawingColor(COLORS::BLACK);
						g.setFontSizeAndBoldness(80, 200);
						g.drawText(screenWidth / 2 - 550, screenHeight / 2 - 80, "There are no saved games!");
						g.endDraw();
						Sleep(1500);
=======

						msg(screenWidth / 2, screenHeight / 2, "Game loaded successfully!");
						computerTurn = 0;

					}

					else {
						drawTicTacToe(gameBoard, xBoard, yBoard, shape);

						msg(screenWidth / 2, screenHeight / 2, "There are no saved games!");
						computerTurn = 0;
>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9

					}

				}
<<<<<<< HEAD
				else if (GetAsyncKeyState(27))
					break;
			}


=======
				else if (GetAsyncKeyState(27))
					break;
			}
>>>>>>> 20cc8fe5fddc419d74ffc95b94ba14937b9c3845
=======
				else if (GetAsyncKeyState(27))
					break;
			}


>>>>>>> 71b366e1d531ac1813b9e3dba7ab70d6df46edf9
			g.setDrawingColor(COLORS::RED);
			g.setDrawingThickness(5);
			g.drawRectangle(xC, yC, 190, 190);

			gameStarted = 1;
			g.endDraw();
			Sleep(150);
		}
	}
}
