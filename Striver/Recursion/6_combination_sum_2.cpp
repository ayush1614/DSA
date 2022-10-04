#include <bits/stdc++.h>
using namespace std;

void combination2(int idx, int target, vector<int> &vec, vector<int> &arr, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(arr);
        return;
    }

    for (int i = idx; i < vec.size(); i++)
    {
        // checking that continously not taking same element , taking the same element in next recursive call
        if (i > idx and vec[i] == vec[i - 1])
            continue;

        if (vec[i] > target)
            break;

        //  take  , recursive call with increased index bcuz same element cannot be taken again, and then not take
        arr.push_back(vec[i]); // take
        combination2(i + 1, target - vec[i], vec, arr, ans);
        arr.pop_back(); // not take
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (auto &i : vec)
        cin >> i;

    int target;
    cin >> target;

    sort(vec.begin(), vec.end()); // sorting because answer need is in sorted manner

    vector<vector<int>> ans;
    vector<int> arr;

    combination2(0, target, vec, arr, ans);

    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";

        cout << endl;
    }
    return 0;
}

// time complexity :  O(2^n) * O(k)
//                    choice of every element  *  average length of putting one DS into another DS

// space complexity : Its unpredicatable : it depends on possible combinations
//  O(k) * x :   average length of combinations and x number of possible combinations