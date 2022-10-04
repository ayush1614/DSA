#include <bits/stdc++.h> //floor value of a number in array
using namespace std;     // TC: O(logn)  | SC: O(n)

int floorValue(vector<int> &vec, int n, int target)
{
    int low = 0, high = n - 1, res = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (vec[mid] == target)
            return mid;

        else if (vec[mid] < target)
        {
            res = mid;      //on moving right may be a possibility , so preserve it 
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
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

    cout << "index is " << floorValue(vec, n, target);

    return 0;
}