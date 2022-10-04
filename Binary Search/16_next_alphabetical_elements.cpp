#include <bits/stdc++.h> // strictly ceil value of alphabets
using namespace std;    //TC: O(logn) |  SC: O(1)

int logic(vector<char> &vec, int n, int target)
{
    int low = 0, high = n - 1;
    int res = 0;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if(vec[mid]<=target)
        low = mid +1 ; 

        else if(vec[mid]>target)
        {
            res = mid ; 
            high = mid - 1 ; 
        }
    }
    return res ; 
}

int main()
{
    int n;
    cin >> n;
    vector<char> vec(n);
    for (auto &i : vec)
        cin >> i;

    char target;
    cin >> target;

    cout << logic(vec, n, target);
    return 0;
}