#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    int target = 4;

    cout << "Binary search: ";
    bool flag = binary_search(vec.begin(), vec.end(), target); // finds present or not
    cout << (flag ? "Present" : "Not Present") << endl;

    cout << "Lower Bound: ";
    int ind = lower_bound(vec.begin(), vec.end(), target) - vec.begin(); // gives first index if present
    if (ind != n and vec[ind] == target)
        cout << ind << endl;

    else
        cout << -1 << endl;

    cout << "Upper Bound: ";
    ind = upper_bound(vec.begin(), vec.end(), target) - vec.begin();//gives last index if present 
    ind-- ;
    if (ind >= 0 and vec[ind] == target)
        cout << ind << endl;
    else
        cout << -1 << endl;

    return 0;
}