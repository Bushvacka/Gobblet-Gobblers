// File: board.h
// Author: D. Troy (troydutton@utexas.edu)
// Date: Spring 2022
// Purpose: Implement all functions necessary for the use of a Gobblet Gobblers board
#include "board.h"

using namespace std;

void printBoard(char board[][SIZE]) {

	for (int i = 0; i < SIZE; i++) {
		// Filler line
		for (int j = 0; j < SIZE; j++) {
			int fg = board[i][j] >= 0 ? WHITE : BLACK;
			int bg = ((i * 3) + j) % 2 == 0 ? BLUE : DARK_BLUE;
			char msg[] = "       ";
			printColoredString(msg, fg, bg);
		}

		cout << endl;

		// Piece line
		for (int j = 0; j < SIZE; j++) {
			int fg = board[i][j] >= 0 ? WHITE : BLACK;
			int bg = ((i * 3) + j) % 2 == 0 ? BLUE : DARK_BLUE;
			char piece = parseSquare(board[i][j]);
			char square[8] = { ' ', ' ', ' ', piece, ' ', ' ', ' ' };
			printColoredString(square, fg, bg);
		}

		cout << endl;

		// Filler line
		for (int j = 0; j < SIZE; j++) {
			int fg = board[i][j] >= 0 ? WHITE : BLACK;
			int bg = ((i * 3) + j) % 2 == 0 ? BLUE : DARK_BLUE;
			char msg[] = "       ";
			printColoredString(msg, fg, bg);
		}

		cout << endl;
	}
}

void printColoredString(char* msg, int fore, int back) {
	cout << ESC << "38;5;" << fore << ";48;5;" << back << "m"; // Begin colored sequence
	while (*msg != '\0') {
		cout << *msg;
		msg++;
	}
	cout << ESC << "0m"; // End colored sequence
}

void printColoredChar(char character, int fore, int back) {
	cout << ESC << "38;5;" << fore << ";48;5;" << back << "m" << character << ESC << "0m";
}

char parseSquare(char square) {
	if ((square & 0x24) != 0) {
		return LARGE;
	}
	else if ((square & 0x12) != 0) {
		return MED;
	}
	else if ((square & 0x9) != 0) {
		return SMALL;
	}
	else {
		return EMPTY;
	}
}

bool terminal(char board[][SIZE]) {
	bool player;
	// Horizontal check
	for (int i = 0; i < SIZE; i++) {
		player = board[i][0] > 0 ? false : true;
		for (int j = 1; j < SIZE; j++) {
			if ((board[i][j] & 0x80) == player) {
				if (j == SIZE - 1) {
					return true;
				}
			}
			else {
				break;
			}
		}
	}
	// Vertical check
	for (int i = 0; i < SIZE; i++) {
		player = board[0][i] > 0 ? false : true;
		for (int j = 1; j < SIZE; j++) {
			if ((board[j][i] & 0x80) == player) {
				if (i == SIZE - 1) {
					return true;
				}
			}
			else {
				break;
			}
		}
	}
	// Diagnol check (Top left -> Bottom right)
	player = board[0][0] > 0 ? false : true;
	for (int i = 1; i < SIZE; i++) {
		if (board[i][i] == player) {
			if (i == SIZE - 1) {
				return true;
			}
		}
		else {
			break;
		}
	}
	// Diagnol check (Bottom left -> Top right)
	player = board[SIZE - 1][0] > 0 ? false : true;
	for (int i = 1; i < SIZE; i++) {
		if (board[SIZE - 1 - i][i] == player) {
			if (i == SIZE - 1) {
				return true;
			}
		}
		else {
			break;
		}
	}
	// All checks failed: not a terminal board
	return false;
}