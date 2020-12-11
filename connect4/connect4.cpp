#include<stdio.h>
#include<stack>

#define ROWS 6
#define COLS 7

// creating a 2D array of ints to represent the gameboard
void createGameBoard(int gameBoard[ROWS][COLS]){

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
            printf("%d\t",gameBoard[i][j]);
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
int switchPlayer(int player) {
    if (player == 1)
        return 2;
    else
        return 1;
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

int main(){

    int gameNotOver = 1;

    //for iterating between players
    int playersTurn = 2;

    int gameBoard[ROWS][COLS];
    
    createGameBoard(gameBoard);
    //printGameBoard(gameBoard);

    while (gameNotOver) {

        // switching player every turn
        playersTurn = switchPlayer(playersTurn);

        bool played = 0;
        
        int column;

        // user input for column
        printf("enter the column you wish to choose (0-6):");
        scanf("%d", &column);
        printf("\n\n");

        if (boardNotFull(gameBoard)) {
            if (columnExists(column)) {
                if (getFirstFreeRow(gameBoard, column) != -1) {
                    
                    int row = getFirstFreeRow(gameBoard, column);
                    
                    gameBoard[row][column] = playersTurn;

                    printGameBoard(gameBoard);
            
                }
                else { printf("Please choose another one, column is full\n"); }
            
            }
            else { printf("column doesn't exist, please choose anther one\n"); }
        
        }
        else { 
            printf("It's a tie, no one wins\n");
            break;
        }


    }
    


    return 0;
}