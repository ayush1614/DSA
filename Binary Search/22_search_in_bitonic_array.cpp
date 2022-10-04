// Given bitonic array and key , find whether it is present in array or not and return index
#include <bits/stdc++.h>
using namespace std;    //TC: O(logn)  |  SC: O(1)

// peak element
int peakElement(vector<int> &vec, int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (mid > 0 and mid < n - 1)
        {
            if (vec[mid - 1] <= vec[mid] and vec[mid + 1] >= vec[mid])
                return mid;

            else if (vec[mid - 1] > vec[mid])
                high = mid - 1;

            else
                low = mid + 1;
        }
        else if (mid == 0)
        {
            if (vec[0] > vec[1])
                return 0;

            else
                return 1;
        }

        else if (mid == n - 1)
        {
            if (vec[n - 1] > vec[n - 2])
                return n - 1;
            else
                return n - 2;
        }
    }
    return -1;
}

// ascending binary search
int ascBsearch(vector<int> &vec, int high, int target)
{
    int low = 0;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (vec[mid] == target)
            return mid;

        else if (vec[mid] > target)
            high = mid - 1;

        else
            low = mid + 1;
    }
    return -1;
}

// descending binary search
int descBsearch(vector<int> &vec, int low, int target)
{
    int high = vec.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (vec[mid] == target)
            return mid;

        else if (vec[mid] > target)
            low = mid + 1;
        else
            high = mid - 1;
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

    int target;
    cin >> target;

    // first find peak element and then apply bsearch on ascending array and descding array
    int peak = peakElement(vec, n);
    int res1 = ascBsearch(vec, peak, target);
    int res2 = descBsearch(vec, peak, target);

    if (res1 == res2 and res1 == -1)
        cout << -1;

    else if (res1 == -1)
        cout << res2;

    else
        cout << res2;
    return 0;
}