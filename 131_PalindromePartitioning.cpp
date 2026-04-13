// TODO: Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// *Example 1:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// *Example 2:
// Input: s = "a"
// Output: [["a"]]

// ?Constraints:
// 1 <= s.length <= 16
// s contains only lowercase English letters.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalin(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;
}

void getAllParts(string s, vector<string> &parts,
                 vector<vector<string>> &ans)
{
    if (s.size() == 0)
    {
        ans.push_back(parts);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string part = s.substr(0, i + 1);
        if (isPalin(part))
        {
            parts.push_back(part);
            getAllParts(s.substr(i + 1), parts, ans);
            parts.pop_back();
        }
    }
}

int main()
{
    string s = "aab";
    vector<vector<string>> ans;
    vector<string> parts;

    getAllParts(s, parts, ans);
    for (auto &n : ans)
    {
        for (int i = 0; i < n.size(); i++)
        {
            cout << n[i] << " ";
        }
    }
    return 0;
}
