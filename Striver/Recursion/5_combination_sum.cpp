#include <bits/stdc++.h>    //taget and array given , find possible unique combinations
using namespace std;

void combinations(int idx, int target, vector<int> &vec, vector<vector<int>> &st, vector<int> &arr)
{
    //when target becomes zero 
    if (target == 0)
    {
        st.push_back(arr);
        return;
    }

    // size exceeded
    if (idx >= vec.size())
        return;

    //when target is less than index 
    if (vec[idx] <= target)
    {
        arr.push_back(vec[idx]); // pick the element 
        combinations(idx, target - vec[idx], vec, st, arr);

        arr.pop_back(); // not pick the element 
        combinations(idx + 1, target, vec, st, arr);
    }

    // when target is less than current index value 
    else
        combinations(idx + 1, target, vec, st, arr);
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

    vector<vector<int>> st;
    vector<int> arr;

    combinations(0, target, vec, st, arr);

    for (auto &it : st)
    {
        for (auto &j : it)
            cout << j << " ";

        cout << endl;
    }
    return 0;
}

// time complexity :  O(2^n) * O(k)
//                    choice of every element  *  average length of putting one DS into another DS

// space complexity : Its unpredicatable : it depends on possible combinations 
//  O(k) * x :   average length of combinations and x number of possible combinations