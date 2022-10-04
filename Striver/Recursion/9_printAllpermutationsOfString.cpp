#include <bits/stdc++.h>
using namespace std;
// Brute  approach :
// TC: O(n! * n) : generating n factorial and traversing freq i.e n  for each factorial
// SC: O(n) + O(n) : storing ds and freq array || if ans is ignored
// Auxilary space: O(n) : no of elements is the depth of recursion
void printPermutation(vector<int> &vec, vector<int> &ds, vector<int> &freq, vector<vector<int>> &ans)
{
    if (ds.size() >= vec.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (!freq[vec[i]])
        {
            ds.push_back(vec[i]);
            freq[vec[i]]++;
            printPermutation(vec, ds, freq, ans);
            freq[vec[i]]--;
            ds.pop_back();
        }
    }
}
int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    vector<int> freq(n + 1, 0);
    vector<vector<int>> ans;
    vector<int> arr;

    printPermutation(vec, arr, freq, ans);

    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}