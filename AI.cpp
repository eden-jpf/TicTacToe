#include <iostream>
#include "Program.h"
#include "AI.h"



char ai = 'x', player = 'o';


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
    if (IsMoveLeft() == false)
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
                    board[i][j] = ai;

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
                    board[i][j] = player;

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

    // Checking for ys for X or O victory.
    for (int y = 0; y < 3; y++)
    {
        if (b[y][0] == b[y][1] && b[y][1] == b[y][2])
        {
            if (b[y][0] == ai)
                return +10;
            else if (b[y][0] == player)
                return -10;
        }
    }

    // Checking for xumns for X or O victory.
    for (int x = 0; x < 3; x++)
    {
        if (b[0][x] == b[1][x] && b[1][x] == b[2][x])
        {
            if (b[0][x] == ai)
                return +10;

            else if (b[0][x] == player)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == ai)
            return +10;
        else if (b[0][0] == player)
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        if (b[0][2] == ai)
            return +10;
        else if (b[0][2] == player)
            return -10;
    }


    return 0;
}

Move FindBestMove(char board[3][3])
{


    int bestVal = -1000;
    Move bestMove;
    bestMove.y = -1;
    bestMove.x = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                
                board[i][j] = ai;

                int moveVal = Minimax(board, 0, false);

                board[i][j] = ' ';

                if (moveVal > bestVal)
                {
                    bestMove.y = i;
                    bestMove.x = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

