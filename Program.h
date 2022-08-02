#pragma once
#include <iostream>


void Outputboard();
void Editboard(char val, int turn);
bool IsMoveLeft();

void MainMenu();
void LocalMenu();
void AIMenu();


void Resetboard();

bool GameOver(int turn, int& winner);



