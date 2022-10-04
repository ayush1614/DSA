#include <bits/stdc++.h>
using namespace std;
#define V 4 // time complexity is O(n^m) | space complexity:  O(n)

// check it is safe to give color 
bool isSafe(int node, int color[], bool graph[][V], int k)
{
    for (int i = 0; i < V; i++)
    {
        if (i != node and graph[i][node] and color[i] == k)// checking for adjacent nodes of node
            return false;
    }
    return true;
}

// backtracking solution
bool graphColoring(int node, bool graph[][V], int m, int color[])
{
    if (node == V)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, i))
        {
            color[node] = i;

            if (graphColoring(node + 1, graph, m, color) == true)
                return true;

            color[node] = 0;
        }
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

    // Number of colors
    int m = 3;
    int color[V] = {0};
    if (graphColoring(0, graph, m, color))
        cout << "Possible ";
    else
        cout << "Not possible";
    return 0;
}