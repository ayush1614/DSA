#include <bits/stdc++.h>
using namespace std;            //TC: O(2^n) * O(n)  | SC: O(n)
typedef long long ll;

void subsequenceSumK(ll idx, vector<ll> &vec, vector<ll> &arr, ll k)
{
    if (idx >= vec.size())
    {
        // if k is zero then subsequenceSumK is found, otherwise not
        if (k == 0)
        {
            for (auto &i : arr)
                cout << i << " ";

            cout << endl;
        }
        return;
    }

    // take the element 
    arr.push_back(vec[idx]);
    subsequenceSumK(idx + 1, vec, arr, k - vec[idx]);

    // not take the element
    arr.pop_back();
    subsequenceSumK(idx + 1, vec, arr, k);
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