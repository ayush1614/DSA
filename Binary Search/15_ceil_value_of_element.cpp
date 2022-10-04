#include <bits/stdc++.h> // ceil value of array
using namespace std;     // TC: O(logn)   |   SC:  O(1)

int ceilValue(vector<int> &vec, int n, int target)
{
    int low = 0, high = n - 1;
    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (vec[mid] == target)
            return mid;

        else if (vec[mid] > target)
        {
            res = mid;          // on moving left , it may be a possibility , so preserve it
            high = mid - 1;
        }
        else
            low = mid + 1;
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

    int target;
    cin >> target;

    cout << ceilValue(vec, n, target);

    return 0;
}