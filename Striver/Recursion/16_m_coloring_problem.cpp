#include <bits/stdc++.h> // Naive solution using recursion , generating all combinations and finding valid combinations
using namespace std;

// Number of vertices in the graph
#define V 4
// print solution
void printSolution(int color[])
{
    cout << "Solution Exists:"
            " Following are the assigned colors \n";
    for (int i = 0; i < V; i++)
        cout << " " << color[i];
    cout << "\n";
}

// check if the colored graph is safe or not
bool isSafe(bool graph[V][V], int color[])
{
    // check for every edge
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] && color[j] == color[i])
                return false;
        }
    }
    return true;
}

/* This function solves the m Coloring problem using recursion. It returns false if the m colours cannot be assigned,
otherwise, return true and prints assignments of colours to all vertices.Please note that there may be more than
one solutions, this function prints one of the feasible solutions.*/
bool graphColoring(bool graph[V][V], int m, int i, int color[V])
{
    // if current index reached end
    if (i == V)
    {
        if (isSafe(graph, color))
        {
            printSolution(color);
            return true;
        }
        return false;
    }

    // traversing for each color
    for (int j = 1; j <= m; j++)
    {
        color[i] = j;

        // Recursion on  rest vertices
        if (graphColoring(graph, m, i + 1, color))
            return true;

        color[i] = 0;
    }

    return false;
}

int main()
{
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; // Number of colors

    int color[V] = {0};
    if (!graphColoring(graph, m, 0, color))
        cout << "Solution does not exist";

    return 0;
}
