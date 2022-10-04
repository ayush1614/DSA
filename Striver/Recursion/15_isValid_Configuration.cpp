#include <bits/stdc++.h> //check the given sudoku has valid configuration or not
using namespace std;     // TC:  O(n*n)  | SC: O(n*n)

bool isValidConfig(vector<vector<char>> &board)
{
    vector<set<int>> rows(9), cols(9), blocks(9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int curr = board[i][j] - '0';
                if (rows[i].count(curr) or cols[j].count(curr) or blocks[(i / 3) * 3 + j / 3].count(curr))
                    return false;

                rows[i].insert(curr);                     // inserting count of that value in row set
                cols[j].insert(curr);                     // inserting count of that value in col set
                blocks[(i / 3) * 3 + j / 3].insert(curr); // inserting values in block set
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (isValidConfig(board) == true)
        cout << "Valid" << endl;

    else
        cout << "Not valid" << endl;
}

/* explanation
For each row, column and block we keep a set of numbers.
If we find a number that was seen already in that row, column or block - return false.
*/