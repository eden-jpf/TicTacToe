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


	int x, y, winner;
	int turn = 1;
	bool hasWon = false;
	std::string repeat;

	std::cout << "\n\nPlayer 1 is X, Player 2 is O\n";
	std::cout << "Player 1 starts...\n";

	do
	{
		while (hasWon == false)
		{
			OutputTable();

			std::cout << "Enter the x coordinate: ";
			std::cin >> x;

			std::cout << "\nEnter the y coordinate: ";
			std::cin >> y;

			switch (turn)
			{
			case 1: // player 1
				table[y][x] = 'X';
				hasWon = CheckIfWon();
				if (hasWon == true)
				{
					winner = turn;
				}
				else
				{
					turn++;
				}
				break;

			case 2: // player 2
				table[y][x] = 'O';
				hasWon = CheckIfWon();
				if (hasWon == true)
				{
					winner = turn;
				}
				else
				{
					turn--;
				}
				break;


			}

		}

		std::cout << "Player " << winner << " has won!\n\n";

		std::cout << "Would you like to play again? y/n: ";
	} while (repeat == "y");

	
}

void OutputTable()
{
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "0 1 2   <- x";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "\n";

		for(int j = 0; j < 3; j++)
		{
			std::cout<< table[i][j] << "|";
		}
		std::cout << i;
	}
	std::cout << "\n";
	std::cout << "\n";
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