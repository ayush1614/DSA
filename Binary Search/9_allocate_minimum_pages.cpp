// given number of pages and students count , Distribute the number of pages among
// all students such that every student has pages and Allocation  of pages is minimum
#include <bits/stdc++.h>
using namespace std; // Tc: O(nlogn) | SC: O(1)

bool isAllocationPossible(vector<int> &vec, int n, int students, int k)
{
    int allocateStud = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] > k)
            return false;

        else if (pages + vec[i] > k)
        {
            allocateStud++;
            pages = vec[i];

            if (allocateStud > students)
                return false;
        }
        else
            pages += vec[i];
    }
    return true;
}

int allocatePages(vector<int> &vec, int n, int students)
{
    int low = INT_MAX, high = 0;
    for (auto &i : vec)
    {
        low = min(low, i);
        high += i;
    }
    int res = 0;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (isAllocationPossible(vec, n, students, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
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

    int students;
    cin >> students;

    cout << allocatePages(vec, n, students);
    return 0;
}