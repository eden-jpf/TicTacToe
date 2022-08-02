#pragma once
#include <iostream>

struct Move;

int Minimax(char board[3][3], int depth, bool isMax);

void testing();


int Evaluate(char b[3][3]);

bool IsMoveLeft(char testtable[3][3]);

Move FindBestMove(char testtable[3][3]);

