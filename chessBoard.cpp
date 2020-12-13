#include<stdio.h>

#define SIZE 8

#define PAWN 1
#define ROOK 2
#define KNIGHT 3
#define BISHOP 4
#define QUEEN 5
#define KING 6

//int pieces = 0;
//int* piecesptr = &pieces;


// 0-15 Pawns
// 16-19 Rooks
// 20-23 Knights
// 24-27 Bishops
// 28-29 Queens
// 30-31 Kings
typedef struct Piece {
	int pictureNumber;
	int type; // pawn/rook....type
	int pieceID; 
	int uniquePieceID;
	int color; // white or black, 1 and 2 respectively
}Piece;


int createUniquePieceID(int color, int type, int pieceID) {
	return (type * 1000 + color*100 +  pieceID );
}


void createGameBoard(int gameBoard[SIZE][SIZE], Piece allPieces[32]) {

	// filling game board with zeros
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			gameBoard[i][j] = 0;
		}
	}


	// declaring white pawns
	for (int arr = 0, mat = 0; arr < 8; arr++, mat++) {
		
		allPieces[arr].color = 1;
		allPieces[arr].type = PAWN;
		allPieces[arr].pieceID = mat + 1;
		allPieces[arr].uniquePieceID = createUniquePieceID(allPieces[arr].color, allPieces[arr].type, allPieces[arr].pieceID);
		gameBoard[1][mat] = allPieces[arr].uniquePieceID;
	}


	// declaring black pawns
	for (int arr = 8, mat = 0; arr < 16; arr++, mat++) {
		allPieces[arr].color = 2;
		allPieces[arr].type = PAWN;
		allPieces[arr].pieceID = mat + 1;
		allPieces[arr].uniquePieceID = createUniquePieceID(allPieces[arr].color, allPieces[arr].type, allPieces[arr].pieceID);
		gameBoard[6][mat] = allPieces[arr].uniquePieceID;
	}


	// declaring Rooks
	for (int i = 16; i <= 19; i++) {
		allPieces[i].color = (i>17) ? 2 : 1; // law as8ar mn 17 color = 2 else 1
		allPieces[i].type = ROOK;
		allPieces[i].pieceID = (i%2==0)? 1 : 2; // law even piece = 1 else 2
		allPieces[i].uniquePieceID = createUniquePieceID(allPieces[i].color, allPieces[i].type, allPieces[i].pieceID);
	}

	gameBoard[0][0] = allPieces[16].uniquePieceID;
	gameBoard[0][7] = allPieces[17].uniquePieceID;
	gameBoard[7][0] = allPieces[18].uniquePieceID;	
	gameBoard[7][7] = allPieces[19].uniquePieceID;

	// declaring Knights
	for (int i = 20; i <= 23; i++) {
		allPieces[i].color = (i > 21) ? 2 : 1; // law as8ar mn 21 color = 2 else 1
		allPieces[i].type = KNIGHT;
		allPieces[i].pieceID = (i % 2 == 0) ? 1 : 2; // law even piece = 1 else 2
		allPieces[i].uniquePieceID = createUniquePieceID(allPieces[i].color, allPieces[i].type, allPieces[i].pieceID);
	}

	gameBoard[0][1] = allPieces[20].uniquePieceID;
	gameBoard[0][6] = allPieces[21].uniquePieceID;
	gameBoard[7][1] = allPieces[22].uniquePieceID;
	gameBoard[7][6] = allPieces[23].uniquePieceID;

	// declaring Bishops
	for (int i = 24; i <= 27; i++) {
		allPieces[i].color = (i > 25) ? 2 : 1; // law as8ar mn 25 color = 2 else 1
		allPieces[i].type = BISHOP;
		allPieces[i].pieceID = (i % 2 == 0) ? 1 : 2; // law even piece = 1 else 2
		allPieces[i].uniquePieceID = createUniquePieceID(allPieces[i].color, allPieces[i].type, allPieces[i].pieceID);
	}

	gameBoard[0][2] = allPieces[24].uniquePieceID;
	gameBoard[0][5] = allPieces[25].uniquePieceID;
	gameBoard[7][2] = allPieces[26].uniquePieceID;
	gameBoard[7][5] = allPieces[27].uniquePieceID;

	// declaring Qeens
	for (int i = 28; i <= 29; i++) {
		allPieces[i].color = (i == 28) ? 1 : 2; // law 28 color =1 else 2
		allPieces[i].type = QUEEN;
		allPieces[i].pieceID = 1; // only one piece
		allPieces[i].uniquePieceID = createUniquePieceID(allPieces[i].color, allPieces[i].type, allPieces[i].pieceID);
	}

	gameBoard[0][3] = allPieces[28].uniquePieceID;
	gameBoard[7][3] = allPieces[29].uniquePieceID;

	// declaring Kings
	for (int i = 30; i <= 31; i++) {
		allPieces[i].color = (i == 30) ? 1 : 2; // law 28 color =1 else 2
		allPieces[i].type = KING;
		allPieces[i].pieceID = 1; // only one piece
		allPieces[i].uniquePieceID = createUniquePieceID(allPieces[i].color, allPieces[i].type, allPieces[i].pieceID);
	}

	gameBoard[0][4] = allPieces[30].uniquePieceID;
	gameBoard[7][4] = allPieces[31].uniquePieceID;

}


void printGameBoard(int gameBoard[SIZE][SIZE], Piece allPieces[32]){
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d\t", gameBoard[i][j]);
		}
		printf("\n\n");
	}
}




int main(){

	int gameBoard[SIZE][SIZE];
	Piece allPieces[32];


	createGameBoard(gameBoard, allPieces);
	printGameBoard(gameBoard, allPieces);

	return 0;
}
