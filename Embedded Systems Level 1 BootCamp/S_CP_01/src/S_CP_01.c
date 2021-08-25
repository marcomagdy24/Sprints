/*
 ============================================================================
 Name        : S_CP_01.c
 Author      : Marco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "xo game/xo.h"

int main(void) {
	int player = Player1, i, choice;
	char board[SIDE][SIDE];
	showInstructions();
	initialize(board);
	char mark;
	do {
		showBoard(board);
		player = (player % 2) ? Player1 : Player2;

		printf("Player %d, enter a number:  ", player);
		fflush(stdout);
		scanf("%d", &choice);
		fflush(stdin);

		mark = (player == Player1) ? Player1x : Player2o;

		if (choice == 1 && board[0][0] == ' ')
			board[0][0] = mark;

		else if (choice == 2 && board[0][1] == ' ')
			board[0][1] = mark;

		else if (choice == 3 && board[0][2] == ' ')
			board[0][2] = mark;

		else if (choice == 4 && board[1][0] == ' ')
			board[1][0] = mark;

		else if (choice == 5 && board[1][1] == ' ')
			board[1][1] = mark;

		else if (choice == 6 && board[1][2] == ' ')
			board[1][2] = mark;

		else if (choice == 7 && board[2][0] == ' ')
			board[2][0] = mark;

		else if (choice == 8 && board[2][1] == ' ')
			board[2][1] = mark;

		else if (choice == 9 && board[2][2] == ' ')
			board[2][2] = mark;

		else {
			printf("Invalid move\n");
			fflush(stdin);
			fflush(stdout);
			player--;
		}
		i = gameOver(board);

		player++;
	} while (i == cont);

	showBoard(board);

	if (i == 1) {
		printf("Player %d win \n", --player);
		fflush(stdout);
	} else {
		printf("Game draw\n");
		fflush(stdout);
	}
	return 0;
}
