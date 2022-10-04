#include <bits/stdc++.h>
using namespace std;            //TC:  O(logn)   |  SC: O(1)
int helper(vector<int> &vec, int key)
{
    // only logic is here
    int low = 0, high = 1;

    while (high > key)  //looping until key lies b/w low and high 
    {
        low = high;
        high = high * 2;
    }

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (vec[mid] == key)
            return mid;

        else if (vec[mid] > key)
            high = mid - 1;

        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    /*As array is infinte , so input is not considerable*/
    vector<int> vec;

    int key = 0;
    cin >> key;
    cout << helper(vec, key);
}