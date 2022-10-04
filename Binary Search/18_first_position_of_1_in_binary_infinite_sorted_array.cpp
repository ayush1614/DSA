// given infinite array , find the posiiton of 1st one in the array
#include <bits/stdc++.h> //TC:  O(logn)   | SC: O(1)
using namespace std;

int helper(vector<int> &vec, int key)
{
    int low = 0, high = 1;

    while (key > high) // looping until key lies b/w low and high
    {
        low = high;
        high = high * 2;
    }

    int res = 0;
    while (low <= high) //code of 1st occurence 
    {
        int mid = (low + high) >> 1;

        if (vec[mid] == key) //there is a possiblity that it is our 1st occ, so store it
        {
            res = mid;
            high = mid - 1;
        }

        else if (vec[mid] > key)
            high = mid - 1;

        else
            low = mid + 1;
    }

    return res ; 
}

int main()
{
    // as array is very large so practically infinte input is not possible*/
    vector<int> vec;

    int key;
    cin >> key;

    cout << helper(vec, key);

    return 0;
}