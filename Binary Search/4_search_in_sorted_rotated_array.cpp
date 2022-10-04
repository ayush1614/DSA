#include <bits/stdc++.h>
using namespace std;

// TC: O(logn) | SC: O(1) || Binary Search 
int logic(vector<int> &vec, int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (vec[mid] == target)
            return mid;
        else if (vec[mid] >= vec[low])
        {
            if (vec[low] <= target and target <= vec[high])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (vec[mid] <= target and target <= vec[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1 ; 
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    int target = 0;
    cin >> target;

    cout << logic(vec, n, target);

    return 0;
}
