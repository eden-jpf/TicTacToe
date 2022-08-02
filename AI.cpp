#include <iostream>
#include "Program.h"
#include "AI.h"

struct Move
{
	int row, col;
};

char player = 'x', opponent = 'o';

void testing()
{
    //         y  x

    /*
    char board[3][3] = {{'x','x','o' },
                        {'o','x',' ' },
                        {' ','o','o' } };

    Move bestMove = FindBestMove(board);

    std::cout << "\n\nThe best move is: " << bestMove.row << " and " << bestMove.col;
    
    */

}

int Minimax(char board[3][3], int depth, bool isMax)
{
    int score = Evaluate(board);

    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then
    // it is a tie
    if (IsMoveLeft(board) == false)
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                if (board[i][j] == ' ')
                {
                    // Make the move
                    board[i][j] = player;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = std::max(best, Minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                if (board[i][j] == ' ')
                {
                    // Make the move
                    board[i][j] = opponent;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = std::min(best,
                        Minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

int Evaluate(char b[3][3])
{

    // Checking for Rows for X or O victory.
    for (int row = 0; row < 3; row++)
    {
        if (b[row][0] == b[row][1] &&
            b[row][1] == b[row][2])
        {
            if (b[row][0] == player)
                return +10;
            else if (b[row][0] == opponent)
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col < 3; col++)
    {
        if (b[0][col] == b[1][col] &&
            b[1][col] == b[2][col])
        {
            if (b[0][col] == player)
                return +10;

            else if (b[0][col] == opponent)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == player)
            return +10;
        else if (b[0][0] == opponent)
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        if (b[0][2] == player)
            return +10;
        else if (b[0][2] == opponent)
            return -10;
    }

    /*

	char cell[3]; // array for positions on the board e.g board[1][2]
	int i, j;


	//check rows
	for (i = 0; i < 3; i++) //y
	{
		for (j = 0; j < 3; j++) //x
		{
			cell[j] = board[i][j];
		}

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
            switch (cell[0])
            {
            case 'X':
                return +10;
                break;
            case 'O':
                return -10;
                break;
            }
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
            switch (cell[0])
            {
            case 'X':
                return +10;
                break;
            case 'O':
                return -10;
                break;
            }
		}
	}

	//check diagonals
	for (i = 0; i < 3; i++)
	{
		cell[i] = board[i][i];

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
            switch (cell[0])
            {
            case 'X':
                return +10;
                break;
            case 'O':
                return -10;
                break;
            }
		}
	}
	for (i = 2, j = 0; i >= 0, j < 3; i--, j++)
	{
		cell[j] = board[j][i];

		if ((cell[0] == cell[1] && cell[1] == cell[2]) && cell[0] != ' ')
		{
			switch (cell[0])
			{
                case 'X':
                    return +10;
                    break;
                case 'O':
                    return -10;
                    break;
			}
		}
	}

    */

    return 0;
}

bool IsMoveLeft(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == ' ')
            {
                return true;
            }
        }
    }
    return false;
}

Move FindBestMove(char board[3][3])
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = player;

                int moveVal = Minimax(board, 0, false);
                //std::cout << "\n\nmove val is: " << moveVal;

                board[i][j] = ' ';

                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    std::cout << "\n\nThe value of the best move is: " << bestVal;
    std::cout << "\n\nThe best move is row: " << bestMove.row << " and col: " << bestMove.col;
    return bestMove;
}
