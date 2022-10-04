#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n) * O(k)    || SC: O(2^n) * O(k) || Auxilary space :  Max recursive call upto n  >>>> k = avg length of subset

void subsetSum2(int idx, vector<int> &vec, vector<int> &arr, vector<vector<int>> &ans)
{
    ans.push_back(arr);

    for (int i = idx; i < vec.size(); i++)
    {
        if (i > idx and vec[i] == vec[i - 1]) //1st time pcicking allowed  but further picking of duplicate not allowed
            continue;

        arr.push_back(vec[i]); // pick
        subsetSum2(i + 1, vec, arr, ans);

        arr.pop_back(); // not pick
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    vector<int> arr;
    vector<vector<int>> ans;

    subsetSum2(0, vec, arr, ans);

    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";

        cout << endl;
    }

    return 0;
}