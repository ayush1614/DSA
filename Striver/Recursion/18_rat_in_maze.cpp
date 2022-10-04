#include <bits/stdc++.h>
using namespace std;

// naive and lengthy code
void ratInMaze(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<string> &ans, string move)
{
    if (i == n - 1 and j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    // Downward recursion
    if (i + 1 < n and !visited[i + 1][j] and grid[i + 1][j])
    {
        visited[i][j] = 1;
        ratInMaze(i + 1, j, n, grid, visited, ans, move + 'D');
        visited[i][j] = 0;
    }

    // Leftward recursion
    if (j - 1 >= 0 and !visited[i][j - 1] and grid[i][j - 1])
    {
        visited[i][j] = 1;
        ratInMaze(i, j - 1, n, grid, visited, ans, move + 'L');
        visited[i][j] = 0;
    }

    // Right ward recursion
    if (j + 1 < n and !visited[i][j + 1] and grid[i][j + 1])
    {
        visited[i][j] = 1;
        ratInMaze(i, j + 1, n, grid, visited, ans, move + 'R');
        visited[i][j] = 0;
    }

    // upper recusrsion
    if (i - 1 >= 0 and !visited[i - 1][j] and grid[i + 1][j])
    {
        visited[i][j] = 1;
        ratInMaze(i + 1, j, n, grid, visited, ans, move);
        visited[i][j] = 0;
    }
}

// optimised and short length code
void ratInMaze2(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<string> &ans, string move, int di[], int dj[])
{
    if (i == n - 1 and j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    // directions  lexicographically
    string dir = "DLRU";
    for (int it = 0; it < 4; it++)
    {
        int nxti = i + di[it]; // next jump on x axis
        int nxtj = j + dj[it]; // next jump on y axis

        // boundary checks and visited checks and grid path availability check
        if (nxti >= 0 and nxtj >= 0 and nxti < n and nxtj < n and !visited[nxti][nxtj] and grid[nxti][nxtj] == 1)
        {
            visited[i][j] = 1; // mark as visited
            ratInMaze2(nxti, nxtj, n, grid, visited, ans, move + dir[it], di, dj);
            visited[i][j] = 0; // mark unvisited for more possible solutions: Backtracking step
        }
    }
}

int main()
{
    int n = 4;
    cin >> n;
    vector<vector<int>> grid = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {0, 1, 0, 1},
                                {1, 1, 1, 1}};

    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    // ratInMaze(0, 0, n, grid, visited, ans, ""); // brute and naive approach

    // optimised way
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};

    ratInMaze2(0, 0, n, grid, visited, ans, "", di, dj);

    for (auto it : ans)
        cout << it << " ";
    return 0;
}

// Time Complexity: O(2^(n^2)).
// The recursion can run upper-bound 2^(n^2) times.
// Space Complexity: O(n^2).
// Output matrix is required so an extra space of size n*n is needed.