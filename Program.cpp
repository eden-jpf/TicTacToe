#include <iostream>
#include "Program.h"

//         y  x
char table[3][3] = {{'O','X','O' },	 
					{'O',' ','O' },
					{'X',' ',' ' } };

/*
char table[3][3] = {{' ',' ',' ' },
					{' ',' ',' ' },
					{' ',' ',' ' } };

*/




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


	

	int turn = 1;

	int winner = NULL;

	bool gameOver = false;

	std::string repeat = NULL;

	std::cout << "\n\nPlayer 1 is X, Player 2 is O\n";
	std::cout << "Player 1 starts...\n";

	do
	{
		while (gameOver == false)
		{
			OutputTable();

			switch (turn)
			{
				case 1: // player 1


					EditTable('X', turn);
					gameOver = GameOver(turn, winner);
					break;

				case 2: // player 2
					
					EditTable('O', turn);
					gameOver = GameOver(turn, winner);
					break;

			}

		}


		if(winner >= 0)
		{
			std::cout << "Player " << winner << " has won!\n\n";
		}
		else
		{
			std::cout << "Draw!\n\n";
		}
		

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

void EditTable(char val, int turn)
{
	int x, y = NULL;
	bool posValid = false;



	while (posValid == false)
	{
		std::cout << "\nPlayer " << turn + 1 << " Enter the x coordinate: ";
		std::cin >> x;

		std::cout << "\nPlayer " << turn + 1 << " Enter the y coordinate: ";
		std::cin >> y;

		if(table[y][x] == ' ')
		{
			table[y][x] = val;
			posValid = true;
		}
		else
		{
			std::cout << "\n\nposition (" << x << "," << y << ") has already been used, please enter another position";
			posValid = false;
		}

	}


}

bool GameOver(int turn, int &winner)
{
	char cell[3]; // array for positions on the table e.g table[1][2]
	int i, j;

	int count = 0;

	//check rows
	for (i = 0; i < 3; i++) //y
	{
		for (j = 0; j < 3; j++) //x
		{
			cell[j] = table[i][j];
		}

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			winner = turn;
			return true;
		}
		else if (cell[0] != ' ' && cell[1] != ' ' && cell[2] != ' ') // check draw
		{
			count++;
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
			winner = turn;
			return true;
		}
	}

	//check diagonals
	for (i = 0; i < 3; i++)
	{
		cell[i] = table[i][i];

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			winner = turn;
			return true;
		}
	}
	for (i = 2, j = 0; i >= 0, j < 3; i--, j++)
	{
		cell[j] = table[j][i];

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			winner = turn;
			return true;
		}
	}

	if (count == 3)
	{
		winner = -1;
		return true; // draw
	}
	else
	{
		return false; // continue
	}

}



/*
TO DO:

	Change the win check to int for -1:loss, 0:draw, 1:win.

	Check if whole table is full and no winners to confirm draw.

	Check if player tries to enter co-ordinates that have already been used.

	Fix local menu not re-doing if user enters y.




*/

// other code
/*int CheckGameState() // 
{
	char cell[3];
	int i;
	int j;

	int count = 0;

	//check rows
	for (i = 0; i < 3; i++) //y
	{
		for (j = 0; j < 3; j++) //x
		{
			cell[j] = table[i][j];			
		}

		if((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			//std::cout << "\nrow win\n";
			return 2; // win
		}
		else if(cell[0] != ' ' && cell[1] != ' ' && cell[2] != ' ') // check draw
		{
			count++;
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
			//std::cout << "\ncol win\n";
			return 2;
		}
	}

	//check diagonals
	for (i = 0; i < 3; i++)
	{
		cell[i] = table[i][i];

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			//std::cout << "\ndia_1 win\n";
			return 2;
		}
	}
	for (i = 2, j = 0; i >= 0, j < 3; i--, j++)
	{
		cell[j] = table[j][i];

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			//std::cout << "\ndia_2 win\n";
			return 2;
		}
	}

	if (count == 3)
	{
		return 1; // draw
	}
	else
	{
		return 0; // continue
	}

	return -1; //loss
}
*/