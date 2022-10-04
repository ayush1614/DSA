#include <bits/stdc++.h>// implementation of lower bound
using namespace std;
int lowerBound(vector<int> nums, int n, int target)
{
    int low = 0, r = n - 1, m = 0;
    while (low < r)
    {
        m = (low + r) / 2;
        if (nums[m] < target)
            low = m + 1;
        else
            r = m;
    }
    return r;
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

    cout<<lowerBound(vec,n,target) ; 
    return 0;
}