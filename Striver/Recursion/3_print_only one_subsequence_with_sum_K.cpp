#include <bits/stdc++.h>
using namespace std; // TC: O(2^n) * O(n)  | SC: O(n)
typedef long long ll;

bool subsequenceSumK(ll idx, vector<ll> &vec, vector<ll> &arr, ll k)
{
    if (idx >= vec.size())
    {
        // if k is zero then subsequenceSumK is found, otherwise not
        if (k == 0)
        {
            for (auto &i : arr)
                cout << i << " ";

            return true;
        }

        //  if condition not satisfied
        return false;
    }

    // take the element
    arr.push_back(vec[idx]);
    if (subsequenceSumK(idx + 1, vec, arr, k - vec[idx]) == true)
        return true;

    // not take the element
    arr.pop_back();
    if (subsequenceSumK(idx + 1, vec, arr, k) == true)
        return true;

    return false;
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

    subsequenceSumK(0, vec, arr, k);
}