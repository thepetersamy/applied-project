#include<stdio.h>
#include<stdlib.h>
#include "CC212SGL.h"
#include <windows.h>
#include <time.h>
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
bool isBoardFull(int gameBoard[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (gameBoard[i][j] == 0)
                return 0;
        }
    }
    return 1;
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

    // ascendingDiagonalCheck 
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (gameBoard[i][j] == playersTurn && gameBoard[i - 1][j + 1] == playersTurn && gameBoard[i - 2][j + 2] == playersTurn && gameBoard[i - 3][j + 3] == playersTurn)
                return 1;
        }
    }
    // descendingDiagonalCheck
    for (int i = 3; i < ROWS; i++) {
        for (int j = 3; j < COLS; j++) {
            if (gameBoard[i][j] == playersTurn && gameBoard[i - 1][j - 1] == playersTurn && gameBoard[i - 2][j - 2] == playersTurn && gameBoard[i - 3][j - 3] == playersTurn)
                return 1;
        }
    }
    return 0;
}

void saveGame(int gameBoard[ROWS][COLS], const char* fileName, int playersTurn) {

    FILE* file = fopen(fileName, "wb+");


    // writing gameboard to file
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
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
int loadGame(int gameBoard[ROWS][COLS], const char* fileName) {

    FILE* file = fopen(fileName, "rb");
    int current;
    int arr[ROWS * COLS + 1];
    int x = 0;
    int playersTurn;

    // reading gameboard into a 1D array
    // the +1 is for the palayersTurn
    for (int i = 0; i < ROWS * COLS + 1; i++) {
        fscanf(file, "%c", &current);
        arr[i] = current;
    }


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
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

void drawGameBoard(int gameBoard[ROWS][COLS], int xStartingBoardCoordinates, int yStartingBoardCoordinates) {
    //setting color of background
    g.fillScreen(COLORS::WHITE);

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


int generateRandomColumn(int gameBoard[ROWS][COLS]) {
    int column;
    time_t t;
    srand((unsigned)time(&t));

    while (getFirstFreeRow(gameBoard, column = rand() % 6) == -1);
    return column;
}




int main() {

    g.setup();

    g.setFullScreenMode();
    g.hideCursor();
    // getting height and width of screen
    int width = g.getWindowWidth();
    int height = g.getWindowHeight();

    // y and x board are for calibrating the game board at the center of the screen
    int xBoard = width / 2 - WIDTH / 2;
    int yBoard = height / 2 - HEIGHT / 2;


    int xToken = xBoard;
    int yToken = yBoard - 115;

    int gameBoard[ROWS][COLS];
    int userInput = 0; //to get user input
    createGameBoard(gameBoard);

    int gameNotOver = 1;

    //for iterating between players
    int playersTurn = 1;

    int playerChoice = 0;
    int singleMultiChoice = 1;
    int gameStarted = 0; //to avoid starting after menu
    int computerTurn = 0; //to activate computer turn


    while (true) {

        g.beginDraw();

        g.fillScreen(COLORS::WHITE);

        int column;
        if (playerChoice == 0)
        {
            g.setDrawingColor(COLORS::BLUE);
            g.setFontSizeAndBoldness(80, 200);
            g.drawText(210, height / 2 - 280, "Connect 4");

            g.setDrawingColor(COLORS::BLACK);
            g.drawText(210, height / 2 - 160, "Singleplayer");
            g.drawText(210, height / 2 - 80, "Multiplayer");
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
            g.drawRectangle(200, height / 2 - (160 / singleMultiChoice), 600, 80);

            g.endDraw();
        }
        else {
            drawGameBoard(gameBoard, xBoard, yBoard);

            if ((kbhit() && gameStarted == 1) || computerTurn == 1)
            {
                if (GetAsyncKeyState(VK_SPACE) || computerTurn == 1)
                {

                    if (playerChoice == 1) {
                        if (playersTurn == 2) {
                            computerTurn = 0;
                            column = generateRandomColumn(gameBoard);

                        }
                        else if (playersTurn == 1) {
                            column = userInput;
                            computerTurn = 1;
                        }
                    }
                    else if (playerChoice == 2)
                        column = userInput;

                    if (!isBoardFull(gameBoard)) {
                        if (columnExists(column)) {
                            if (getFirstFreeRow(gameBoard, column) != -1) {

                                int row = getFirstFreeRow(gameBoard, column);

                                gameBoard[row][column] = playersTurn;

                                if (playerWonHorizontally(gameBoard, playersTurn) || playerWonVertically(gameBoard, playersTurn) || playerWonDiagonally(gameBoard, playersTurn)) {
                                    drawGameBoard(gameBoard, xBoard, yBoard);

                                    g.setDrawingColor(COLORS::LIME);
                                    g.drawSolidRectangle(width / 2 - 280, height / 2 - 80, 510, 80);
                                    g.setDrawingColor(COLORS::BLACK);
                                    g.setFontSizeAndBoldness(80, 200);
                                    char tmp[50];
                                    sprintf(tmp, "Player %d WON!!!", playersTurn);
                                    g.drawText(width / 2 - 280, height / 2 - 80, tmp);
                                    g.endDraw();

                                    gameNotOver = 0;
                                    break;
                                }


                            }
                            else {
                                g.setDrawingColor(COLORS::LIME);
                                g.drawSolidRectangle(width / 2 - 550, height / 2 - 80, 1300, 80);
                                g.setDrawingColor(COLORS::BLACK);
                                g.setFontSizeAndBoldness(80, 200);
                                g.drawText(width / 2 - 550, height / 2 - 80, "Please choose another one, column is full");
                                g.endDraw();
                                Sleep(1500);
                                continue;
                            }

                        }// merged from terminal based game but has no use here
                        else {
                            printf("column doesn't exist, please choose anther one\n");

                            continue;
                        }

                    }
                    else {
                        g.setDrawingColor(COLORS::LIME);
                        g.drawSolidRectangle(width / 2 - 550, height / 2 - 80, 1300, 80);
                        g.setDrawingColor(COLORS::BLACK);
                        g.setFontSizeAndBoldness(80, 200);
                        g.drawText(width / 2 - 550, height / 2 - 80, "It's a tie, no one wins");
                        g.endDraw();
                        Sleep(1500);
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

                else if (GetAsyncKeyState(27)) {
                    break;
                }
                else if (GetAsyncKeyState('S'))
                {
                    saveGame(gameBoard, "c4", playersTurn);
                    g.setDrawingColor(COLORS::LIME);
                    g.drawSolidRectangle(width / 2 - 550, height / 2 - 80, 1300, 80);
                    g.setDrawingColor(COLORS::BLACK);
                    g.setFontSizeAndBoldness(80, 200);
                    g.drawText(width / 2 - 550, height / 2 - 80, "Game saved successfully!");
                    g.endDraw();
                    Sleep(1500);
                }
                else if (GetAsyncKeyState('L'))
                {
                    if (fileExists("c4")) {
                        playersTurn = loadGame(gameBoard, "c4");
                        g.setDrawingColor(COLORS::LIME);
                        g.drawSolidRectangle(width / 2 - 550, height / 2 - 80, 1300, 80);
                        g.setDrawingColor(COLORS::BLACK);
                        g.setFontSizeAndBoldness(80, 200);
                        g.drawText(width / 2 - 550, height / 2 - 80, "Game loaded successfully!");
                        g.endDraw();
                        Sleep(1500);
                    }
                    else {
                        g.setDrawingColor(COLORS::LIME);
                        g.drawSolidRectangle(width / 2 - 550, height / 2 - 80, 1300, 80);
                        g.setDrawingColor(COLORS::BLACK);
                        g.setFontSizeAndBoldness(80, 200);
                        g.drawText(width / 2 - 550, height / 2 - 80, "There are no saved games!");
                        g.endDraw();
                        Sleep(1500);
                    }
                }
            }
            gameStarted = 1;


            if (playersTurn == 1)
                g.setDrawingColor(COLORS::YELLOW);
            else if (playersTurn == 2)
                g.setDrawingColor(COLORS::RED);
            g.drawSolidCircle(xToken, yToken, 90);


            //printf("%d", userInput);//test
            Sleep(150);
            g.endDraw();

        }

    }
    Sleep(2000);
    getch();

    return 0;
}
