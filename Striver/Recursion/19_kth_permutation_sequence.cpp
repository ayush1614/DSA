#include <bits/stdc++.h>
using namespace std;

// Naive and Brute way : TC: O(n)*O(n)  | SC: O(n)
void allPermutations(int idx, int n, vector<int> &vec, vector<vector<int>> &ans)
{
    if (idx >= n)
    {
        ans.push_back(vec);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        swap(vec[idx], vec[i]);
        allPermutations(idx + 1, n, vec, ans);
        swap(vec[idx], vec[i]);
    }
}

// Optimised way:
// TC: O(n) * O(n) >> TC: O(n) = finding the n numbers and after n numbers we have erase it and find out for n-1 and erase takes O(n) time
// SC: O(n) : for storing the vector
string permute(int n, int k)
{
    int fact = 1;
    vector<int> vec;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        vec.push_back(i);
    }
    vec.push_back(n);
    string str = "";
    k -= 1;
    while (true)
    {
        str += to_string(vec[k / fact]);
        vec.erase(vec.begin() + k / fact);
        if (vec.size() == 0)
            break;

        k = k % fact;
        fact = fact / vec.size();
    }

    return str;
}
int main()
{
    int n = 3;
    cin >> n;

    vector<int> vec;
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
        vec.push_back(i);

    allPermutations(0, n, vec, ans); // brute force
    sort(ans.begin(), ans.end());
    int k;
    cin >> k;

    // for (auto &i : ans[k - 1])
    // {
    //     cout << i << " ";
    // }

    cout << permute(n, k); //  optimised way

    return 0;
}

/*
Optimised way  logic
for ex n = 4  , k = 17 ;

find the permutation starting from 1 i.e. 6 from 2 is also 6 possiblities and so on
so on total 24 combinations possible having 6 possiblities of starting number

actually we need k = 16  , starting indexing from 0 ,  so 16 / 6 = 2 , 16 % 6 = 4 = k (new K)
our combination start from 2nd index number i.e 3  and of 3's combinations it is 4th combination

now again repeat the process: with k = 4 th seq needed starting from 3 among (1,2,4) ;
now every index has 1 , 2 and 4 has 2 possible combinations so k / 2 = 2 , k % 2 = 0 = k (new K)
this time we have our combinations number starting at index 2nd index i.e 4
so our combination consist of {3,4} and  again start the process with k = 0

*/