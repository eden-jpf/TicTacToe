#include <iostream>
#include "Program.h"
#include "AI.h"

char board[3][3] = { {' ',' ',' ' },
				{' ',' ',' ' },
				{' ',' ',' ' } };

struct Move
{
	int row, col;
};


int gameType;

int main()
{
    MainMenu();
	//testing();
}

void MainMenu()
{
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
				AIMenu();
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
	std::string repeat;

	do
	{
		int turn = 1;
		int winner = NULL;
		bool gameOver = false;

		Resetboard();

		std::cout << "\n\nPlayer 1 is x, Player 2 is O\n";
		std::cout << "Player 1 starts...\n";

		while (gameOver == false)
		{
			Outputboard();
			switch (turn)
			{
				case 1: // player 1
					Editboard('x', turn);
					gameOver = GameOver(turn, winner);
					turn++;
					break;

				case 2: // player 2
					Editboard('o', turn);
					gameOver = GameOver(turn, winner);
					turn--;
					break;
			}
		}

		Outputboard();

		if(winner >= 0)
		{
			std::cout << "\nPlayer " << winner << " has won!\n\n";
		}
		else
		{
			std::cout << "\nDraw!\n\n";
		}
		

		std::cout << "Would you like to play again? y/n: ";
		std::cin >> repeat;

	} while (repeat == "y");

	
}

void AIMenu()
{
	std::string repeat;

	do
	{
		int turn = 1;
		int winner = NULL;
		bool gameOver = false;

		Resetboard();

		std::cout << "\n\nPlayer is O, AI is x\n";
		std::cout << "Player starts...\n";

		while (gameOver == false)
		{
			Outputboard();
			switch (turn)
			{
			case 1: // player 1
				Editboard('x', turn);
				gameOver = GameOver(turn, winner);
				turn++;
				break;

			case 2: // AI

				std::cout << "\n\nAi turn";

				Move bestMove = FindBestMove(board);

				board[bestMove.col][bestMove.row] = 'o';

				gameOver = GameOver(turn, winner);
				turn--;
				break;
			}
		}

		Outputboard();

		if(winner == 2)
		{
			std::cout << "\nAI has won!\n\n";
		}
		else
		{
			std::cout << "\nYou have won!\n\n";
		}

		std::cout << "Would you like to play again? y/n: ";
		std::cin >> repeat;

	} while (repeat == "y");
}

void Editboard(char val, int turn)
{
	int x, y = NULL;
	bool posValid = false;

	while (posValid == false)
	{
		std::cout << "\nPlayer " << turn << " Enter the x coordinate: ";
		std::cin >> x;

		std::cout << "\nPlayer " << turn << " Enter the y coordinate: ";
		std::cin >> y;

		if(board[y][x] == ' ')
		{
			board[y][x] = val;
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
	char cell[3]; // array for positions on the board e.g board[1][2]
	int i, j;

	int count = 0;

	//check rows
	for (i = 0; i < 3; i++) //y
	{
		for (j = 0; j < 3; j++) //x
		{
			cell[j] = board[i][j];
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
			cell[j] = board[j][i];
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
		cell[i] = board[i][i];

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			winner = turn;
			return true;
		}
	}
	for (i = 2, j = 0; i >= 0, j < 3; i--, j++)
	{
		cell[j] = board[j][i];

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

void Outputboard()
{
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "0 1 2   <- x";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "\n";

		for (int j = 0; j < 3; j++)
		{
			std::cout << board[i][j] << "|";
		}
		std::cout << i;
	}
	std::cout << "\n";
	std::cout << "\n";
}

void Resetboard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

bool IsMoveLeft()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				return true;
			}
		}
	}
	return false;
}

