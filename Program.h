#pragma once
#include <iostream>


extern struct Move 
{
	int x, y;
};

Move GetMove(int turn);

void EditBoard(char val, int turn, Move move);

void MainMenu();

void LocalMenu();

void AIMenu();

void Outputboard();

void Resetboard();

bool GameOver(int turn, int& winner);

bool IsMoveLeft();

