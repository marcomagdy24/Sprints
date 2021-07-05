/*
 * xo.h
 *
 *  Created on: Jul 5, 2021
 *      Author: marco
 */

#ifndef XO_GAME_XO_H_
#define XO_GAME_XO_H_

#include <stdio.h>
#include <stdlib.h>

#define SIDE 3
#define Player1 1
#define Player2 2

#define Player1x 'X'
#define Player2o 'O'

enum bool {
	cont = -1, draw, win
};

int gameOver(char board[][SIDE]);
int checkWin(char board[][SIDE]);
void showInstructions();
void initialize(char board[][SIDE]);
void showBoard(char board[][SIDE]);

#endif /* XO_GAME_XO_H_ */
