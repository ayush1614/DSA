#include <bits/stdc++.h>
using namespace std; // TC: O(2^n) * O(n)  | SC: O(n)
typedef long long ll;

ll subsequenceSumK(ll idx, vector<ll> &vec, vector<ll> &arr, ll k)
{
    if (idx >= vec.size())
    {
        // if k is zero then subsequenceSumK is found, otherwise not
        if (k == 0)
            return 1;

        //  if condition not satisfied
        return 0;
    }

    // take the element
    arr.push_back(vec[idx]);
    ll left = subsequenceSumK(idx + 1, vec, arr, k - vec[idx]);

    // not take the element
    arr.pop_back();
    ll right = subsequenceSumK(idx + 1, vec, arr, k);

    return left + right;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> vec(n), arr;
    for (auto &i : vec)
        cin >> i;

    ll k = 0;
    cin >> k;

    cout<<subsequenceSumK(0, vec, arr, k);
}