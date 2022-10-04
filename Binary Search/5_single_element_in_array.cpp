// find the single element in array , here every element appears twice and a single element must present 
#include <bits/stdc++.h>        //TC: O(logn)  | SC: O(1)
using namespace std;
int singleElement(vector<int> &vec, int n)
{
    if (n == 1)
        return vec[0];

    int low = 0, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (vec[mid] == vec[mid ^ 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return vec[low] ; 
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    cout<<"Single element is: " << singleElement(vec, n);
    return 0;
}