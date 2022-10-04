#include <bits/stdc++.h>
using namespace std;

// BACKTRACKING SOLUTION WITH OPTIMATION USING HASHING
// TIME COMPLEXITY:  O(N! * N)
// SPACE COMPLEXITY: O(N)
void nQueen(int col, int n, vector<string> &board, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, vector<vector<string>> &ans)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 and upperDiagonal[n - 1 + col - row] == 0 and lowerDiagonal[row + col] == 0)
        {
            leftRow[row] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            lowerDiagonal[row + col] = 1;

            board[row][col] = 'Q';

            nQueen(col + 1, n, board, leftRow, upperDiagonal, lowerDiagonal, ans);

            board[row][col] = '.';

            leftRow[row] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
            lowerDiagonal[row + col] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    string str(n, '.');
    vector<string> board(n, str);
    vector<vector<string>> ans;

    vector<int> leftRow(n, 0);
    vector<int> upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

    nQueen(0, n, board, leftRow, upperDiagonal, lowerDiagonal, ans);

    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << endl;
        cout << endl;
    }

    return 0;
}