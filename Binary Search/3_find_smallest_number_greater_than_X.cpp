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

    int ind = upper_bound(vec.begin(), vec.end(), target) - vec.begin();
    if (ind<n)
        cout << vec[ind] << endl;
    else
        cout << -1 << endl;

    return 0;
}