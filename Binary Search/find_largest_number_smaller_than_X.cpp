#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    int target;
    cin >> target;

    int ind = lower_bound(vec.begin(), vec.end(), target) - vec.begin();
    ind-- ; 
    if (ind >= 0)
        cout << vec[ind] << endl;
    else
        cout << -1 << endl;

    return 0;
} 