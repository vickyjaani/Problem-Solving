#include <iostream>
using namespace std;

bool sudokuSolver(int board[][9])
{
    for (int i = 0; i < 9; i++)
    {
        cout << i << " row\n";
        for (int j = 0; j < 9; j++)
        {
            //if(i == 1)
            cout << j << " cloumn";
            if (board[i][j] >= 1)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k != j)
                        if (board[i][k] == board[i][j])
                            return false;
                    if (k != i)
                        if (board[k][j] == board[i][j])
                            return false;
                }
                for (int m = i - (i % 3); m < (i - (i % 3)) + 3; m++)
                {
                    for (int n = j - (j % 3); n < (j - (j % 3)) + 3; n++)
                    {
                        if (m != i && n != j)
                            if (board[m][n] == board[i][j])
                                return false;
                    }
                }
            }

            if (board[i][j] == 0)
            {
                int possible[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
                for (int k = 0; k < 9; k++)
                {
                    possible[board[i][k] - 1] = 0;
                    possible[board[k][j] - 1] = 0;
                }
                for (int m = i - (i % 3); m < (i - (i % 3)) + 3; m++)
                {
                    for (int n = j - (j % 3); n < (j - (j % 3)) + 3; n++)
                    {
                        possible[board[m][n] - 1] = 0;
                    }
                }
                int flag = 0;
                for (int k = 0; k < 9; k++)
                {
                    if (possible[k] == 0)
                        flag++;
                }
                if (flag == 9)
                    return false;
                for (int k = 0; k < 9; k++)
                {
                    if (possible[k] == 1)
                    {
                        board[i][j] = k + 1;
                        return sudokuSolver(board);
                    }
                }
            }
        }
    }
    return true;
}

int main()
{

    int n = 9;
    int board[9][9];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    if (sudokuSolver(board))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
