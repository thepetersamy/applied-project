#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 3

void createGameBoard(int gameBoard[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			gameBoard[i][j] = 0;
		}
	}
}

void printGameBoard(int gameBoard[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d\t", gameBoard[i][j]);
		}
		printf("\n\n");
	}
}

int switchPlayer(int playerTurn){
	return playerTurn == 1 ? 2 : 1;
}



bool isOccupied(int gameBoard[SIZE][SIZE], int x, int y) {
	return gameBoard[x][y] == 0 ? 0 : 1;
}


bool coordinatesExist(int x, int y) {
	return ((x >= 0 && x < 3) && (y >= 0 && y < 3));
}


void placeToken(int gameBoard[SIZE][SIZE], int playersTurn, int x, int y){
	gameBoard[x][y] = playersTurn;
}

bool isBoardFull(int gameBoard[SIZE][SIZE], int playersTurn, int x, int y) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; i < SIZE; j++) {
			if (gameBoard[i][j] == 0)
				return 1;
		}
	}
	return 0;
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
	}
	return 0;
}


bool playerWondiagonally(int gameBoard[SIZE][SIZE], int playersTurn) {
	if (gameBoard[0][0] == playersTurn && gameBoard[1][1] == playersTurn && gameBoard[2][2] == playersTurn){
		return 1;
	}
	if (gameBoard[0][2] == playersTurn && gameBoard[1][1] == playersTurn && gameBoard[2][0] == playersTurn) {
		return 1;
	}
	return 0;


	//int counter = 0;
	//for (int i = 0; i < SIZE; i++) {
	//	if (gameBoard[i][i] == playersTurn) {
	//		counter++;
	//	}
	//}

	//for (int i = SIZE-1; i >= 0; i--) {
	//	if (gameBoard[i][i] == playersTurn) {
	//		counter++;
	//	}
	//}


	
}


void twoPlayerGame(int gameBoard[SIZE][SIZE]) {


	int gameNotOver = 1;

	int playersTurn = 1;

	createGameBoard(gameBoard);
	printGameBoard(gameBoard);

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
					printGameBoard(gameBoard);
					if (playerWonVertically(gameBoard, playersTurn) || playerWonHorizontally(gameBoard, playersTurn) || playerWondiagonally(gameBoard, playersTurn)) {

						printf("player %d WON!!!", playersTurn);
						break;
					}




				}
				else {
					printf("block is occuipied please choose another one");
					continue;
				}
			}
			else {
				printf("coordinates you entered does not exist");
				continue;
			}
		}
		else {
			printf("board is full, its a tie!");
			gameNotOver = 0;
			break;
		}
		playersTurn = switchPlayer(playersTurn);
	}

}

bool playerAboutToWinHorizontally(int gameBoard[SIZE][SIZE], int *rowNumber) {
	// is real player about to win horizontally?
	int counter = 0;
	for (int column = 0; column < SIZE; column++) {
		for (int row = 0; row< SIZE; row++) {
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

void computersPlay(int gameBoard[SIZE][SIZE], int *x, int *y) {
	int rowNumber;
	if (playerAboutToWinHorizontally(gameBoard, &rowNumber)) {

	}


}



void generateRandomCordinates(int gameBoard[SIZE][SIZE], int* x, int* y) {
	time_t t;
	srand((unsigned) time(&t));
	//printf("%d\n", rand() % 3);
	
	while (isOccupied(gameBoard, *x = rand() % 3, *y = rand() % 3));
}

void onePlayerGame(int gameBoard[SIZE][SIZE]) {



	int gameNotOver = 1;

	int playersTurn = 1;

	createGameBoard(gameBoard);
	printGameBoard(gameBoard);

	while (gameNotOver) {
		bool played = 0;

		int x, y;


		if (playersTurn == 1) {
			// user input for column
			printf("**PLAYER %d**\n", playersTurn);
			printf("plaese enter the (x,y) coordinates you wish to place the token in:");

			scanf("%d%d", &x, &y);
			printf("\n\n");

		}
		else if (playersTurn) {
			generateRandomCordinates(gameBoard, &x, &y);
			printf("computer played at (%d,%d)\n\n", x , y );
		}
		if (isBoardFull) {
			if (coordinatesExist(x, y)) {

				if (!isOccupied(gameBoard, x, y)) {

					placeToken(gameBoard, playersTurn, x, y);
					printGameBoard(gameBoard);
					if (playerWonVertically(gameBoard, playersTurn) || playerWonHorizontally(gameBoard, playersTurn) || playerWondiagonally(gameBoard, playersTurn)) {

						printf("COMPUTER WON!!!!");
						break;
					}




				}
				else {
					printf("block is occuipied please choose another one");
					continue;
				}
			}
			else {
				printf("coordinates you entered does not exist");
				continue;
			}
		}
		else {
			printf("board is full, its a tie!");
			gameNotOver = 0;
			break;
		}
		playersTurn = switchPlayer(playersTurn);
	}


}



int main() {
	int x, y;


	int gameBoard[SIZE][SIZE];    // = { {2,2,2}, {2,2,2}, {2,2,2} };
	int playerChoice;

	

	printf("please enter 1 or 2 for a sigleplayer or multiplayer game: ");
	scanf("%d",&playerChoice);

	if (playerChoice == 2) {
		twoPlayerGame(gameBoard);
	}
	else if (playerChoice == 1) {
		onePlayerGame(gameBoard);
	}
	

	return 0;
}




