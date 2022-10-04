#include <bits/stdc++.h>
using namespace std;            //TC: O(2*n) * O(n)   | SC: O(n) ; 
typedef long long ll;
//concept of take not take
void subsequence(ll idx, vector<ll> &vec, vector<vector<ll>> &ans, vector<ll> &tmp)
{
    if (idx == vec.size())
    {
        ans.push_back(tmp);
        return;
    }

    // take or pick the element 
    tmp.push_back(vec[idx]);
    subsequence(idx + 1, vec, ans, tmp);

    // not take and pick the element
    tmp.pop_back(); //removing the added element
    subsequence(idx + 1, vec, ans, tmp);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (auto &i : vec)
        cin >> i;

    vector<vector<ll>> ans;
    vector<ll> tmp;

    subsequence(0, vec, ans, tmp);

    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";

        cout << endl;
    }

    return 0;
}