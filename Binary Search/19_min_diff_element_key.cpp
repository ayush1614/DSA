// given array and key  , find the minimum difference 
#include <bits/stdc++.h>  //TC: O(logn)  | SC: O(1)
using namespace std;

//Approach 1: Using the low and high conditions of binary search because 
// loop breaks high<low , so we get adjacent of the key 

//Approach 2 : Using the ceil and floor values 
int minDiffElement(vector<int> &vec, int n, int key)
{
    int low = 0, high = n - 1;
    int ind1 = 0, ind2 = 0;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (vec[mid] == key)
        {
            ind1 = ind2 = mid;
            break;
        }

        else if (vec[mid] < key)
        {
            ind1 = mid;
            low = mid + 1;
        }

        else
        {
            ind2 = mid;
            high = mid - 1;
        }
    }
    int h = vec[ind1] ; 
    h = vec[ind2]  ; 
    return min(abs(vec[ind1] - key), abs(vec[ind2] - key));
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    int key = 0;
    cin >> key;

    cout << minDiffElement(vec, n, key);
    return 0;
}