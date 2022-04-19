#pragma once

// File: board.h
// Author: D. Troy (troydutton@utexas.edu)
// Date: Spring 2022
// Purpose: Declare all functions necessary for the use of a Gobblet Gobblers board
// Boards come in the form of a square matrix (3x3 by default)
//  + |   | o 
// ---|---|---
//    | @ | +
// ---|---|---
//  o |   |   
// Each square is occupied by a +, o, or @
// Such that a + can only be placed on an open square
// An o can be placed on an open square or over a +
// An @ can be placed on an open square, over a +, or over an o
// Each square is represented by a signed 8 bit number in the way that:
// Bit 0: Presence of +(Player 1)
// Bit 1: Presence of o(Player 1)
// Bit 2: Presence of @(Player 1)
// Bit 3: Presence of +(Player 2)
// Bit 4: Presence of o(Player 2)
// Bit 5: Presence of @(Player 2)
// Bit 7: Player that placed the last Gobbler(0-Player 1, 1-Player 2)
// Bit 6 is skipped so that the player can be determined by the sign
// e.g. the board shown above would be encoded as: {{0x01, 0x0, 0x90}, {0x0, 0xA0, 0x01}, {0x02, 0x0, 0x0}}
#pragma once

#include <iostream>

// Game constants
#define SIZE 3
#define P1 0x07
#define P2 0x38
#define EMPTY ' '
#define SMALL '+'
#define MED 'o'
#define LARGE '@'

// ANSI Color constants
#define ESC "\033["
#define WHITE 15
#define BLACK 16
#define DARK_BLUE 27
#define BLUE 33

// printBoard - Print a GG board to the terminal
// Input: board - multidimensional array of numbers representing pieces
// Output: None
void printBoard(char board[][SIZE]);

// printColoredString - Print a string to the screen with colored foreground and background
// Input: msg	- Null-terminated array of ASCII characters to print
//		  fore	- ANSI colour code for foreground
//		  back	- ANSI colour code for background
// Output: None
void printColoredString(char* msg, int fore, int back);

// printColoredChar - Print a character to the screen with colored foreground and background
// Input: character	- ASCII character to print
//		  fore		- ANSI colour code for foreground
//		  back		- ANSI colour code for background
// Output: None
void printColoredChar(char character, int fore, int back);

// parseSquare - Return the most recently placed piece on a square
// Input: square - GG square
// Output: Largest piece on the square (i.e. SMALL, MED, LARGE)
char parseSquare(char square);

// terminal - Determines whether a GG game is finished
// Input: board - multidimensional array for numbers representing pieces
// Output: True if the game is complete, False otherwise.
bool terminal(char board[][SIZE]);

// winner - Determines the winner of a GG game, assumes the board is a terminal.
// Input: board - multidimensional array for numbers representing pieces
// Output: True if the Player 1 wins, False otherwise
bool winner(char board[][SIZE]);

// makeMove - Place a piece on a GG board.
// Input: board   - multidimensional array for numbers representing pieces
//		  player  - player placing the piece. False: P1, True: P2
//		  piece   - Size of piece to place on the square
//		  target  - index of square to place the piece on
//		  origin  - index of square to 
// Output: True if the piece was successfully placed, false otherwise.
bool makeMove(char board[][SIZE], bool player, char piece, int target, int origin);