/*
 * xo.c
 *
 *  Created on: Jul 5, 2021
 *      Author: marco
 */

#include "xo.h"

int gameOver(char board[][SIDE]) {
	return ((signed int) checkWin(board));
}

int checkDraw(char board[][SIDE]) {
	int checkCondition = cont;
	for (int i = 0; i < SIDE; i++) {
		for (int j = 0; j < SIDE; j++) {
			if (board[i][j] == ' ') {
				return cont;
			} else {
				checkCondition = draw;
			}
		}
	}
	return checkCondition;
}

int checkWin(char board[][SIDE]) {
	for (int i = 0; i < SIDE; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]
				&& board[i][0] != ' ')
			return win;
	}
	for (int i = 0; i < SIDE; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]
				&& board[0][i] != ' ')
			return win;
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
			&& board[0][0] != ' ')
		return win;

	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]
			&& board[0][2] != ' ')
		return win;

	else {
		return (checkDraw(board));
//		printf("[Debug] Check condition is %d\n", checkCondition);
	}

}

void winnerWinner(int winner) {
	if (winner == Player1)
		printf("Player1 win\n");
	else
		printf("Player2 win\n");
}

void showBoard(char board[SIDE][SIDE]) {
	printf("     |     |    \n");
	printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);
	printf("_____|_____|____\n");
	printf("     |     |    \n");
	printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);
	printf("_____|_____|____\n");
	printf("     |     |    \n");
	printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);
	printf("     |     |    \n");
}

void showInstructions() {
	printf("\tXO Game\n\n");
	printf("Choose a cell numbered from 1 to 9 as below" " and play\n\n");
	printf("Player 1 (X)  -  Player 2 (O)\n\n");
	printf("     |     |    \n");
	printf("  1  |  2  |  3 \n");
	printf("_____|_____|____\n");
	printf("     |     |    \n");
	printf("  4  |  5  |  6 \n");
	printf("_____|_____|____\n");
	printf("     |     |    \n");
	printf("  7  |  8  |  9 \n");
	printf("     |     |    \n");
	printf("\n\n");

}

void initialize(char board[SIDE][SIDE]) {
	for (int i = 0; i < SIDE; i++) {
		for (int j = 0; j < SIDE; j++) {
			board[i][j] = ' ';
		}
	}
	printf("[INFO] Board Initialized\n\n");
}
