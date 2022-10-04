// given a sorted array such that some of its element are swapped with its adjacents only
//  i.e.  i - 1 and i + 1 , we have to find the target element
#include <bits/stdc++.h>
using namespace std; // TC: O(logn) |  SC: O(1)

int logic(vector<int> &vec, int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (vec[mid] == target) //check at current element
            return mid;

        else if (mid + 1 <= high and vec[mid + 1] == target) // check at mid + 1 element 
            return mid + 1;

        else if (mid - 1 >= low and vec[mid - 1] == target) // check at mid - 1 element
            return mid - 1;

        else if (vec[mid] > target) // if mid greater than target , reduce right search space
            high = mid - 2;

        else       
            low = mid + 2;
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

    cout << logic(vec, n, target);

    return 0;
}
