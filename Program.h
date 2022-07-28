#pragma once
#include <iostream>


void OutputTable();
void EditTable(char val, int turn);
void MainMenu();
void LocalMenu();
void ResetTable();

bool GameOver(int turn, int& winner);