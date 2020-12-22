#include<stdio.h>
//#include<sqlite3.h>
#define ROWS 6
#define COLS 7

// creating a 2D array of ints to represent the gameboard
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
















//bool playerWonDiagonally(int gameBoard[ROWS][COLS], int playersTurn) {
    //// counter to check if 4 tokens of the same player in a column
    //int counter = 0, rowstart;
    //for (int row = 0; row < ROWS - 1-row; row++) {
    //    int  col;
    //    for (row = 0, col = COLS; row < ROWS && col <= 0; row++, col--) {
    //        if (gameBoard[row][col] == playersTurn) {
    //            counter++;
    //            if (counter == 4) 
    //                return 1;
    //        }
    //        else {
    //            counter = 0;
    //        }
    //    }
    //}

    //// top-left to bottom-right - red diagonals
    //for (int column = 1; column < COLS - 4; rowstart++) {
    //    counter = 0;
    //    int row, colstart;
    //    for (row = 0, column = 0; row < ROWS && column < COLS; row++, column++) {
    //        if (gameBoard[row][column] == playersTurn) {
    //            counter++;
    //            if (counter >= 4) return 1;
    //        }
    //        else {
    //            counter = 0;
    //        }
    //    }
    //}
    //return 0;
//}

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


int main() {

    int gameNotOver = 1;

    //for iterating between players
    int playersTurn = 1;

    int gameBoard[ROWS][COLS];

    createGameBoard(gameBoard);
    printGameBoard(gameBoard);

    while (gameNotOver) {


        bool played = 0;

        int column;

        // user input for column
        printf("**PLAYER %d**\n", playersTurn);
        printf("Enter the column you wish to choose (0-6):");
        scanf("%d", &column);
        printf("\n\n");

        if (boardNotFull(gameBoard)) {
            if (columnExists(column)) {
                if (getFirstFreeRow(gameBoard, column) != -1) {

                    int row = getFirstFreeRow(gameBoard, column);

                    gameBoard[row][column] = playersTurn;

                    printGameBoard(gameBoard);

                    if (playerWonHorizontally(gameBoard, playersTurn) || playerWonVertically(gameBoard, playersTurn) ) {
                        gameNotOver = 0;
                        printf("Player %d WON!!!", playersTurn);
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
            break;
        }

        // switching player every turn
        playersTurn = switchPlayer(playersTurn);

    }



    return 0;
}