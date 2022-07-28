#pragma once
#include <iostream>


void OutputTable();
void EditTable(char val, int turn);
int CheckGameState();
bool GameOver(int turn, int& winner);
void MainMenu();
void LocalMenu();