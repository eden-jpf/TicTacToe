#include <iostream>
#include "Program.h"

//         y  x
char table[3][3] = {{'O','X','O' },	 
					{'O','X','X' },
					{'X','O','O' } };



int main()
{
    OutputTable();
	//EditTable(0, 0, ' ');
	bool hasWon = CheckIfWon();

	if(hasWon)
	{
		std::cout << "\nWon";
	}
	else
	{
		std::cout << "\nLost";
	}


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
			
			//std::cout << "\n" << cell[j];
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
			//std::cout << "\n" << cell[j];
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
		//std::cout << "\n" << cell[i];

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