// given sorted 2d matrix and find key present in matrix
#include <bits/stdc++.h>
using namespace std; // TC:  O(n+m)   |  Sc: O(1)

// using binary search
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), j = matrix[0].size() - 1, i = 0;
    while (i < m and j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    int target;
    cin >> target;

    if (searchMatrix(matrix, target))
        cout << "Present" << endl;

    else
        cout << "Not present" << endl;

    return 0;
}
