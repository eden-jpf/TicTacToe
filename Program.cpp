#include <iostream>
#include "Program.h"

//         y  x
char table[3][3] = {{' ',' ',' ' },	 
					{' ',' ',' ' },
					{' ',' ',' ' } };



int main()
{
	MainMenu();


}


void MainMenu()
{
	int gameType;
	do
	{
		std::cout << "0 : Quit\n";
		std::cout << "1 : Local 1v1\n";
		std::cout << "2 : Play against AI (WIP)\n";
		std::cout << "Choice: ";
		std::cin >> gameType;

		switch (gameType)
		{
			case 0:
				std::cout << "\nThanks for playing!\n";
				break;
			case 1:
				LocalMenu();
				break;
			case 2:
				std::cout  << "Not yet implemented\n";
				break;
			default:
				std::cout << "Invalid Choice\n";
				break;
		}


	
	} while (gameType != 0);



}

void LocalMenu()
{
	std::cout << "\n\nPlayer 1 is X, Player 2 is O\n";

	/*
	do
	{
		OutputTable();



	} while ();
	*/
}

void OutputTable()
{
	std::cout << "\n";
	std::cout << "0 1 2";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "\n";

		for(int j = 0; j < 3; j++)
		{
			std::cout<< table[i][j] << "|";
		}
		std::cout << i;
	}
}

void EditTable(int x, int y, char val)
{
	std::cin >> x;
	std::cin >> y;
	std::cin >> val;


	table[y][x] = val;
	OutputTable();
}

bool CheckIfWon()
{
	char cell[3];
	int i;
	int j;

	//check rows
	for (i = 0; i < 3; i++) //y
	{
		for (j = 0; j < 3; j++) //x
		{
			cell[j] = table[i][j];			
		}

		if((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			return true;
		}
	}


	//check columns
	for (i = 0; i < 3; i++) //y
	{
		for (j = 0; j < 3; j++) //x
		{
			cell[j] = table[j][i];
		}

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			return true;
		}
	}


	//check diagonals
	for (i = 0; i < 3; i++)
	{
		cell[i] = table[i][i];

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			return true;
		}
	}
	for (i = 2, j = 0; i >= 0, j < 3; i--, j++)
	{
		cell[j] = table[j][i];

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			return true;
		}
	}


	return false;
}