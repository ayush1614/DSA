// median of two sorted arrays using the binary search
#include <bits/stdc++.h> //TC: O(log(min(n,m))) | SC: O(1)
using namespace std;

double median(vector<int> &vec1, vector<int> &vec2, int n1, int n2)
{
    if (n1 > n2) // binsary search ong lower size array so that the bsearch  TC is small
        return median(vec2, vec1, n2, n1);

    int low = 0, high = n1;
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;        // elements of 1st array
        int cut2 = (n1 + n2 + 1) / 2 - cut1; // elements of 2nd array

        int left1 = (cut1 == 0) ? INT_MIN : vec1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : vec2[cut2 - 1];
        int right1 = (cut1 == n1) ? INT_MAX : vec1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : vec2[cut2];

        if (left1 <= right2 and left2 <= right2) // must cond for median
        {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }

        else if (left1 > right2)
            high = cut1 - 1;

        else
            low = cut1 + 1;
    }
    return 1;
}
int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> vec1(n1), vec2(n2);

    for (auto &i : vec1)
        cin >> i;

    for (auto &i : vec2)
        cin >> i;

    if (n1 == 0 and n2 == 0) // if both n1 and n2 are zero
        cout << "Not possible";

    else if (n1 == 0) // if n1 is zero , median is of 2nd array
    {
        if (n2 & 1)
            cout << vec2[n2 / 2];

        else
            cout << (vec2[(n2 / 2) - 1] + vec2[((n2 / 2) + 1) - 1]) / 2.0;
    }

    else if (n1 == 0) // if n2 is zero ,median is of 1st array
    {
        if (n1 & 1)
            cout << vec1[n1 / 2];

        else
            cout << (vec1[(n1 / 2) - 1] + vec1[((n1 / 2) + 1) - 1]) / 2.0;
    }
    else
        cout << median(vec1, vec2, n1, n2);

    return 0;
}