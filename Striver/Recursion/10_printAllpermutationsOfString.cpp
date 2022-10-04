#include <bits/stdc++.h>
using namespace std;
//TC: O(n!) * O(n)
//SC: O(n)
//Aux Stack: O(n)
void permutations(int idx, vector<int> &vec, vector<vector<int>> &ans)
{
    if (idx >= vec.size())
    {
        ans.push_back(vec);
        return;
    }

    for (int i = idx; i < vec.size(); i++)
    {
        swap(vec[i], vec[idx]);
        permutations(idx + 1, vec, ans);
        swap(vec[i], vec[idx]);
    }
}
int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    vector<vector<int>> ans;

    permutations(0, vec, ans);

    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";

        cout << endl;
    }
    return 0;
}