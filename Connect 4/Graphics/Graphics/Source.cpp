#include<stdio.h>
#include<stdlib.h>
#include "CC212SGL.h"
#include <windows.h>
#pragma comment(lib, "CC212SGL.lib")

#define ROWS 6
#define COLS 7

#define HEIGHT 600
#define WIDTH 700

CC212SGL g;

void createGameBoard(int gameBoard[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = 0;
        }
    }
}


// printing the gameboard
void printGameBoard(int gameBoard[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", gameBoard[i][j]);
        }
        printf("\n\n");
    }
}

// check if column exists
// cols from (0-6) only
bool columnExists(int column) {
    if (column < 0 || column>6)
        return 0;
    return 1;
}


// check for first free row in the gameboard
//starting downwards for optimization
int getFirstFreeRow(int gameBoard[ROWS][COLS], int column) {
    for (int row = ROWS; row >= 0; row--) {
        if (!gameBoard[row][column])
            return row;
    }
    return -1;
}
// function to switch player
int switchPlayer(int playersTurn) {

    return playersTurn == 1 ? 2 : 1;
}
// checking if the board is full, hence a tie
bool boardNotFull(int gameBoard[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; i < COLS; j++) {
            if (gameBoard[i][j] == 0)
                return 1;
        }
    }
    return 0;
}
// implement with counter and break when counter == 4
bool playerWonHorizontally(int gameBoard[ROWS][COLS], int playersturn) {

    // counter to check if 4 tokens of the same player in a row
    int counter = 0;

    for (int row = ROWS - 1; row >= 0; row--) {

        // opt: checking if the third column has a token same as players turn
        // because if not no 4 tokens can be placed in a row
        if (gameBoard[row][3] == playersturn) {
            for (int column = COLS - 1; column >= 0; column--) {
                if (gameBoard[row][column] == playersturn) {
                    counter++;
                    if (counter == 4) {
                        return 1;
                    }
                }
                else {
                    counter = 0;
                }
            }
        }
        counter = 0;
    }
    return 0;
}
bool playerWonVertically(int gameBoard[ROWS][COLS], int playersturn) {
    // counter to check if 4 tokens of the same player in a column
    int counter = 0;

    // opt starting from downwards of the board to save processing power
    for (int column = COLS - 1; column >= 0; column--) {

        // opt: checking if the third column has a token same as players turn
        // because if it doesn't then the player can't place
        if (gameBoard[2][column] == playersturn) {
            for (int row = ROWS - 1; row >= 0; row--) {
                if (gameBoard[row][column] == playersturn) {
                    counter++;
                    if (counter == 4) {
                        return 1;
                    }
                }
                else {
                    counter = 0;
                }
            }
        }
        counter = 0;
    }
    return 0;
}
bool playerWonDiagonally(int gameBoard[ROWS][COLS], int playersTurn) {

    return 0;
}
void saveGame(int gameBoard[ROWS][COLS], const char* fileName) {

    FILE* file = fopen(fileName, "w+");



    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            char current[10];
            sprintf(current, "%d", gameBoard[i][j]);
            fputs(current, file);
        }
    }
    printf("[Game Saved]");

    fclose(file);

}
void loadGame(int gameBoard[ROWS][COLS], const char* fileName) {

    FILE* file = fopen(fileName, "r");
    int current;
    int arr[ROWS * COLS];
    int x = 0;


    for (int i = 0; i < ROWS * COLS; i++) {
        fscanf(file, "%c", &current);
        arr[i] = current;
    }


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = char(arr[x++] - '0');
        }
    }
    fclose(file);
    printf("[Game Loaded]");
}


void drawGameBoard(int gameBoard[ROWS][COLS], int xStartingBoardCoordinates, int yStartingBoardCoordinates) {
    //setting color of background
    g.fillScreen(COLORS::BLACK);

    g.setDrawingColor(COLORS::BLUE);
    g.setDrawingThickness(30);
    g.drawSolidRectangle(xStartingBoardCoordinates, yStartingBoardCoordinates, WIDTH, HEIGHT); //border of gameboard

    g.setDrawingThickness(0);

    for (int row = 0, j = yStartingBoardCoordinates; row < ROWS; row++, j += 100) {
        for (int column = 0, i = xStartingBoardCoordinates; column < COLS; column++, i += 100) {

            if (gameBoard[row][column] == 0) {
                g.setDrawingColor(COLORS::WHITE);
                g.drawSolidCircle(i, j, 90);
            }
            else if (gameBoard[row][column] == 1) {
                g.setDrawingColor(COLORS::YELLOW);
                g.drawSolidCircle(i, j, 90);
            }
            else if (gameBoard[row][column] == 2) {
                g.setDrawingColor(COLORS::RED);
                g.drawSolidCircle(i, j, 90);
            }
        }
    }

}



int main() {

    g.setup();

    g.setFullScreenMode();
    g.hideCursor();
    // getting height and width of screen
    int width = g.getWindowWidth();
    int height = g.getWindowHeight();

    // y and x board are for calibrating the game board at the center of the screen
    int xBoard = width / 2 - WIDTH/2;
    int yBoard = height / 2 - HEIGHT/2;


    int xToken = xBoard;
    int yToken = yBoard - 115;

    int gameBoard[ROWS][COLS];
    int userInput = 0; //to get user input
    createGameBoard(gameBoard);

    int gameNotOver = 1;

    //for iterating between players
    int playersTurn = 1;



    while (true) {

        g.beginDraw();

        drawGameBoard(gameBoard, xBoard, yBoard);



        if (kbhit)
        {         
            if (GetAsyncKeyState(VK_SPACE))
            {
                if (boardNotFull(gameBoard)) {
                    if (columnExists(userInput)) {
                        if (getFirstFreeRow(gameBoard, userInput) != -1) {

                            int row = getFirstFreeRow(gameBoard, userInput);

                            gameBoard[row][userInput] = playersTurn;

                            if (playerWonHorizontally(gameBoard, playersTurn) || playerWonVertically(gameBoard, playersTurn)) {
                                gameNotOver = 0;
                                printf("Player %d WON!!!", playersTurn);
                                drawGameBoard(gameBoard, xBoard, yBoard);
                                break;
                            }


                        }
                        else {
                            printf("Please choose another one, column is full\n");
                            continue;
                        }

                    }
                    else {
                        printf("column doesn't exist, please choose anther one\n");
                        continue;
                    }

                }
                else {
                    printf("It's a tie, no one wins\n");
                    drawGameBoard(gameBoard, xBoard, yBoard);
                    break;
                }

                // switching player every turn
                playersTurn = switchPlayer(playersTurn);

            }
            else if (GetAsyncKeyState(VK_RIGHT) && xToken < xBoard + HEIGHT)
            {
                xToken += 100;
                userInput++;
            }
            else if (GetAsyncKeyState(VK_LEFT) && xToken > xBoard)
            {
                xToken -= 100;
                userInput--;
            }

            else if (GetAsyncKeyState(27))
                break;
        }
        if(playersTurn == 1)
            g.setDrawingColor(COLORS::YELLOW);
        else if(playersTurn == 2)
            g.setDrawingColor(COLORS::RED);
        g.drawSolidCircle(xToken, yToken, 90);


        //printf("%d", userInput);//test

        Sleep(150);
        g.endDraw();
    }
    getch();

    return 0;
}

