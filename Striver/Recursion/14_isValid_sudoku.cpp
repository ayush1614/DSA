#include <bits/stdc++.h> // check the given  sudoku solution is valid or not
using namespace std;
bool isValidSudoku(vector<vector<char>> &board)
{
    vector<bool> hashSet(10, false);

    // for unique row values
    for (int i = 0; i < 9; i++)
    {
        fill(hashSet.begin(), hashSet.end(), false);
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int idx = board[i][j] - '0';
                if (hashSet[idx] == true)
                    return false;

                hashSet[idx] = true;
            }
        }
    }
    // cout<<"Row " ;
    // for unique column values
    for (int i = 0; i < 9; i++)
    {
        fill(hashSet.begin(), hashSet.end(), false);
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int idx = board[i][j] - '0';
                if (hashSet[idx] == true)
                    return false;

                hashSet[idx] = true;
            }
        }
    }

    // for unique block value
    int n = 9;
    for (int i = 0; i < n - 2; i += 3)
    {
        for (int j = 0; j < n - 2; j += 3)
        {
            fill(hashSet.begin(), hashSet.end(), false);
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    int r = i + k;
                    int c = j + l;

                    if (board[r][c] != '.')
                    {
                        int idx = board[r][c] - '0';

                        if (hashSet[idx] == true)
                            return false;

                        hashSet[idx] = true;
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
    vector<vector<char>> board = {{'7', '9', '2', '1', '5', '4', '3', '8', '6'},
                                  {'6', '4', '3', '8', '2', '7', '1', '5', '9'},
                                  {'8', '5', '1', '3', '9', '6', '7', '2', '4'},
                                  {'2', '6', '5', '9', '7', '3', '8', '4', '1'},
                                  {'4', '8', '9', '5', '6', '1', '2', '7', '3'},
                                  {'3', '1', '7', '4', '8', '2', '9', '6', '5'},
                                  {'1', '3', '6', '7', '4', '8', '5', '9', '2'},
                                  {'9', '7', '4', '2', '1', '5', '6', '3', '8'},
                                  {'5', '2', '8', '6', '3', '9', '4', '1', '7'}};

    if (isValidSudoku(board))
        cout
            << "Valid";

    else
        cout << "Not Valid";

    return 0;
}

/*
explanation :
3 conditions should be satified

1. every column contains unique digits ranging from 1-9
2. every row contains unique digits ranging from 1-9
3. every block contains unique digits ranging from 1-9

Here we check that already filled values should be unique
*/
