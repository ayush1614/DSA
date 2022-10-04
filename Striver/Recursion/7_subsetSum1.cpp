#include <bits/stdc++.h>
using namespace std;

//TC: O(2^n)        SC: O(2^n)
void subsetSum(int idx, int sm, vector<int> &vec, vector<int> &ans)
{
    if (idx >= vec.size())
    {
        ans.push_back(sm);
        return;
    }

    subsetSum(idx + 1, sm + vec[idx], vec, ans); // pick 

    subsetSum(idx + 1, sm, vec, ans); // not pick
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (auto &i : vec)
        cin >> i;

    vector<int> ans;
    subsetSum(0, 0, vec, ans);

    sort(ans.begin(),ans.end());    //TC: O(2^n log(2^n))

    for (auto &i : ans)
        cout << i << " ";
}