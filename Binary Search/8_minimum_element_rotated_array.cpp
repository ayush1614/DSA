// search the minimum element in rotated array
#include <bits/stdc++.h> // TC: O(logn)  | SC: O(1)
using namespace std;

int minElement(vector<int> &vec, int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (mid < high and vec[mid + 1] <= vec[mid])
            return vec[mid + 1];

        else if (mid > low and vec[mid - 1] >= vec[mid])
            return vec[mid];

        else if (vec[low] <= vec[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return vec[0];
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    cout << minElement(vec, n);
    return 0;
}

// application
//  also helps in telling the number of times array is rotated