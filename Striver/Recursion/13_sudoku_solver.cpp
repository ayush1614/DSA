#include <bits/stdc++.h>
using namespace std;
//TC: O(9*(n*n)) : for every empty space we have 9 choices
//SC: O(n*n) : space for storing sudoku

//function to check whether sudoku is valid or not
bool isValid(int row, int col, vector<vector<int>> &vec, int k)
{
    for (int i = 0; i < 9; i++)
    {
        if (vec[i][col] == k) // duplicacy check in rows
            return false;

        if (vec[row][i] == k) // duplicacy check in columns
            return false;

        if (vec[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k)  // checking in a block :below explanation
            return false;
    }
    return true;
}

// main logic function 
bool sudokuSolver(vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] == 0)     // if empty space present i.e. zero
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isValid(i, j, vec, k))  // first checking that is it valid to fill 
                    {
                        vec[i][j] = k;

                        if (sudokuSolver(vec) == true)      // if valid then just move forward 
                            return true;

                        else        // if not valid then just revert the changes
                            vec[i][j] = 0;
                    }
                }
                return false;   // returns false when we not able to fill anything 
            }
        }
    }
    return true;   // returns when we have not any empty spaces means sudolu has been filled 
}

int main()
{
    int n = 9;
    vector<vector<int>> vec = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    sudokuSolver(vec);
   
    for (auto &j : vec)
    {
        for (auto &i : j)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
explanation :
3 conditions should be satified

1. every column contains unique digits ranging from 1-9
2. every row contains unique digits ranging from 1-9
3. every block contains unique digits ranging from 1-9

INSIDE isValid function
here , for row it is i/3 bcuz we have to increase the row when all blocks of that row is checked  
whereas , for column , it it i%3 , bcuz we have to increase the column in each row like 0 1 2 , for this we 
do modulo by 3
*/