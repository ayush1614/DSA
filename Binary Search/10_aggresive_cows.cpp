// given the number of stalls with coodinates given , and number of cows
// we have to put cows in these stalls such that minimum distance between is maximum

#include <bits/stdc++.h>
using namespace std;        //Tc: O(nlogn)  | SC : O(n)

bool isPossible(vector<int> &vec, int n, int cows, int k)
{
    int coord = vec[0];
    int allotedCows = 1;
    for (int i = 1; i < n; i++)
    {
        if (vec[i] - coord >= k)
        {
            allotedCows++;
            coord = vec[i];
        }

        if (allotedCows >= cows)
            return true;
    }
    return false;
}

int maxDistance(vector<int> &vec, int n, int cows)
{
    int low = vec[0], high = vec[n - 1] - vec[0];
    int res = 0;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (isPossible(vec, n, cows, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    sort(vec.begin(), vec.end());
    int cows;
    cin >> cows;

    cout << maxDistance(vec, n, cows);
    return 0;
}