#include <iostream>
#include "Program.h"
#include "AI.h"
		// y x			//x
char board[3][3] = { {' ',' ',' ' }, //y
				{' ',' ',' ' },
				{' ',' ',' ' } };

int main()
{
    MainMenu();
}

void MainMenu()
{
	int gameType;
	
	// Just a menu to chose what type of game
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

void LocalMenu() //Function to handle some logic and UI for local 1v1
{
	std::string repeat;

	Move playerMove; //struct to store player input (x,y)

	do
	{
		int turn = 1;
		int winner = NULL;
		bool gameOver = false;

		Resetboard(); // sets all values of board = to ' '

		std::cout << "\n\nPlayer 1 is x, Player 2 is O\n";
		std::cout << "Player 1 starts...\n";

		while (gameOver == false)
		{
			Outputboard();
			switch (turn)
			{
				case 1: // player 1
					playerMove = GetMove(turn); //Get user input
					EditBoard('x', turn, playerMove); //Check input and edit the board
					gameOver = GameOver(turn, winner); 
					turn++; //increment turn if the game isnt over
					break;

				case 2: // player 2
					playerMove = GetMove(turn);
					EditBoard('o', turn, playerMove);
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

		Move aiMove; //struct for AI input (x,y)
		Move playerMove;

		Resetboard();

		std::cout << "\n\nPlayer is x, AI is o\n";
		std::cout << "Player starts...\n";

		while (gameOver == false)
		{
			Outputboard();
			switch (turn)
			{
				case 1: // player 1
					playerMove = GetMove(turn);
					EditBoard('x', turn, playerMove);
					gameOver = GameOver(turn, winner);
					turn++;
					break;

				case 2: // AI

					std::cout << "\n\nAi turn";

					aiMove = FindBestMove(board); //finds the optimal move
					board[aiMove.y][aiMove.x] = 'o'; //edit board
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

Move GetMove(int turn) //Get player input
{
	Move move;

	std::cout << "\nPlayer " << turn << " Enter the x coordinate: ";
	std::cin >> move.x;

	std::cout << "\nPlayer " << turn << " Enter the y coordinate: ";
	std::cin >> move.y;

	return move;
}

void EditBoard(char val, int turn, Move move) //check the player input and edit board according to input
{
	bool posValid = false;

	while (posValid == false)
	{
		if(board[move.y][move.x] == ' ')
		{
			board[move.y][move.x] = val;
			posValid = true;
		}
		else
		{
			std::cout << "\n\nPosition (" << move.x << "," << move.y << ") has already been used, please enter another position";
			move = GetMove(turn);
			posValid = false;
		}
	}
}

bool GameOver(int turn, int &winner)
{
	/*

	char cell[3]; // array for positions on the board e.g board[1][2]
	int i, j;

	//check ys
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

	}

	//check xumns
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




	if(IsMoveLeft() == false)
	{
		return true;
	}

	return false;
	*/

	// Checking for ys for X or O victory.
	for (int y = 0; y < 3; y++)
	{
		if (board[y][0] == board[y][1] && board[y][1] == board[y][2] && board[y][0] != ' ')
		{
			winner = turn;
			return true;
		}
	}

	// Checking for xumns for X or O victory.
	for (int x = 0; x < 3; x++)
	{
		if (board[0][x] == board[1][x] && board[1][x] == board[2][x] && board[0][x] != ' ')
		{
			winner = turn;
			return true;
		}
	}

	// Checking for Diagonals for X or O victory.
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		winner = turn;
		return true;
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		winner = turn;
		return true;
	}

	if (IsMoveLeft() == false)
	{
		return true; //draw
	}

	return false; //continue
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
			std::cout << board[i][j] << "|"; //lines to seperate board
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

