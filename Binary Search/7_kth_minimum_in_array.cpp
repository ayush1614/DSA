// find the kth minimum element in tow sorted arrays using binary search
#include <bits/stdc++.h> // TC: O(log(min(n,m)))   | SC: O(1)
using namespace std;

int kthSmallestElement(vector<int> &vec1, vector<int> &vec2, int n1, int n2, int k)
{
    if (n1 > n2) // binary search on lower size array
        return kthSmallestElement(vec2, vec1, n2, n1, k);

    // here low is min(0 , k - n2) ,because it is possible that k >n2 so some elemnts are present to be mandatory
    int low = max(0, k - n2), high = min(k, n1);

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : vec1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : vec2[cut2 - 1];
        int right1 = (cut1 == n1) ? INT_MAX : vec1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : vec2[cut2];

        if (left1 <= right2 and left2 <= right1) // cond for kth elemnt
            return max(left1, left2);

        else if (left1 > right2)
            high = cut1 - 1;

        else
            low = cut1 + 1;
    }
    return -1;
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

    int k;
    cin >> k;

    if (k > (n1 + n2))
        cout << "Not possible ";

    else if (n1 == 0)
        cout << vec2[n2 - 1];
    else if (n2 == 0)
        cout << vec1[n1 - 1];
    else
        cout << kthSmallestElement(vec1, vec2, n1, n2, k);
    return 0;
}