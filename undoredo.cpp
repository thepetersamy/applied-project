#include<stdio.h>
#define SIZE 100
#define ROWS 7
#define COLS 6
int top = -1;
//int stack[SIZE];

int allMoves[SIZE][ROWS][COLS];

void push(int allMoves[SIZE][ROWS][COLS], int currentMove[ROWS][COLS]) {
	if (top == (SIZE)) {
		printf("Exception: stack overflow!\n");
		return;
	}

	//gameBoardStorer[++top][2][2] = number;

	
	for (int j = 0, x = 0; j < ROWS; j++, x++) {
		for (int k = 0, y = 0; k < COLS; k++, y++) {
			allMoves[top][j][k] = currentMove[x][y];
		}
	}
	

}

void pop() {
	if (top == -1)
		printf("Exception: stack already empty!");
	else
		top--;
}

void printArray(int array[]) {

	for (int i = 0; i < top; i++) {
		printf("%d\t", array[i]);
	}

}

void printAllMoves(int allMoves[SIZE][ROWS][COLS]) {
	for (int i = 0; i < top; i++) {
		for (int j = 0; j < ROWS; j++) {
			for (int k = 0; k < COLS; k++) {
				printf("%d\t", allMoves[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
}


int main() {

	




	//push(stack, 0);
	//push(stack, 1);
	//push(stack, 2);
	//push(stack, 3);
	//push(stack, 4);
	//push(stack, 5);
	//pop(stack);


	//printArray(stack);



	//copying array into multidimensional array

	int array[2][2] = { {1,2}, {3,4} };
	//int array2[5] = { 6,7,8,9,10 };
	//int array3[5] = { 11,12,13,14,15 };

	int store[3][2][2];

	int arrx = 0;
	int arry = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0, x = 0; j < 2; j++, x++) {
			for (int k = 0, y = 0; k < 2; k++, y++) {
				store[i][j][k] = array[x][y];
			}
		}
	}

	


	return 0;
}
