#include <bits/stdc++.h>
using namespace std;
// TIME COMLEXITY: O(n*2^M)   | Space Complexity:  O(n*n)
// check for palindrome
bool isPalindrome(string str, int start, int end)
{
    while (start <= end)
    {
        if (str[start++] != str[end--])
            return false;
    }
    return true;
}
void palindromePartition(string str, int idx, vector<string> &vec, vector<vector<string>> &ans)
{
    if (idx == str.length()) // when lists reaches last
    {
        ans.push_back(vec);
        return;
    }

    for (int i = idx; i < str.length(); i++)
    {
        if (isPalindrome(str, idx, i))
        {
            vec.push_back(str.substr(idx, i - idx + 1));
            palindromePartition(str, i + 1, vec, ans);

            vec.pop_back(); // so that we can check for other possibilities also, so remove it
        }
    }
}

int main()
{
    string str;
    cin >> str;

    vector<string> vec; // stores individual list of substrings for every recursion
    vector<vector<string>> ans;

    palindromePartition(str, 0, vec, ans);

    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";

        cout << endl;
    }
}