#include <iostream>
#include "board.h"

using namespace std;


int main() {
	char board[SIZE][SIZE] = { {0x01, 0x0, 0x90}, {0x0, 0xA0, 0x01}, {0x02, 0x0, 0x0} };
	printBoard(board);
	cout << terminal(board) << endl;
}