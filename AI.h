#pragma once
#include <iostream>



int Minimax(char board[3][3], int depth, bool isMax);

int Evaluate(char b[3][3]);

Move FindBestMove(char testtable[3][3]);

