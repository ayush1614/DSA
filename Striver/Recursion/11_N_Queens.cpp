#include <bits/stdc++.h>
using namespace std;

// Backtracking solution
// TIME COMPLEXITY : O(n! * n)  ::: bcause for every possiblity we check it is valid or not,
// SPACE COMPLEXITY: O(n) * O(n)    :::    so its not very efficient
bool isSafe(int row, int col, int n, vector<string> &board)
{
    // check for upper primary diagonal
    int i = row, j = col;
    while (i >= 0 and j >= 0) // O(n)
    {
        if (board[i][j] == 'Q')
            return false;

        i--;
        j--;
    }

    // for current row check
    for (int i = 0; i <= col; i++) // O(n)
    {
        if (board[row][i] == 'Q')
            return false;
    }

    // lower 2ndary diagonal arrow
    i = row, j = col;
    while (i < n and j >= 0) // O(n)
    {
        if (board[i][j] == 'Q')
            return false;

        i++;
        j--;
    }

    return true;
}
void nQueen(int col, int n, vector<string> &board, vector<vector<string>> &ans)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n, board))
        {
            board[row][col] = 'Q';
            nQueen(col + 1, n, board, ans);
            board[row][col] = '.'; // remove 'Q' bcuz , we have to chk for next possibility
        }
    }
}
int main()
{
    int n = 4;
    cin >> n;

    string str(n, '.');
    vector<string> board(n, str);
    vector<vector<string>> ans;

    nQueen(0, n, board, ans);

    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << endl;
        cout << endl;
    }
}