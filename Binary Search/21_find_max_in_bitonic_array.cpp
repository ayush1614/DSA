// Given bitonic array : an array with first increasing values and then decreasing values
// find max in that array
#include <bits/stdc++.h> //TC: O(logn)  | SC: O(1)
using namespace std;

// similiar to finding the peak element
int maxInBitonicArray(vector<int> &vec, int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (mid < n - 1 and mid > 0) // checking for peak within the range
        {
            if (vec[mid + 1] <= vec[mid] and vec[mid - 1] <= vec[mid])
                return mid;

            else if (vec[mid - 1] > vec[mid])
                high = mid - 1;

            else
                low = mid + 1;
        }

        else if (mid == 0) // if mid is zero check with next element
        {
            if (vec[0] > vec[1])
                return 0;

            else
                return 1;
        }
        else if (mid == n - 1) // if mid is n-1 element check with previous element
        {
            if (vec[n - 1] > vec[n - 2])
                return n - 1;

            else
                return n - 2;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    cout << maxInBitonicArray(vec, n);

    return 0;
}