#include <bits/stdc++.h> //implementation of upper bound
using namespace std;

int upperBound(vector<int> &vec, int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (vec[mid] <= target)
            low = mid + 1;

        else
        high = mid - 1 ; 
    }

    return low ; 
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

    cout<<upperBound(vec,n,target) ; 
    return 0;
}