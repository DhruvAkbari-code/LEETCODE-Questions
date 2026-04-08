// TODO: Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// TODO: The solution set must not contain duplicate subsets. Return the solution in any order.

//* Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

//* Example 2:
// Input: nums = [0]
// Output: [[],[0]]

//? Constraints:
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void allSubsets(vector<int> &arr, vector<int> &ans, int i, vector<vector<int>> &subsets)
{
    if (i == arr.size())
    {
        subsets.push_back(ans);
        return;
    }

    ans.push_back(arr[i]);
    allSubsets(arr, ans, i + 1, subsets);
    ans.pop_back();

    int idx = i + 1;
    while (idx < arr.size() && arr[idx] == arr[i])
    {
        idx++;
    }

    allSubsets(arr, ans, idx, subsets);
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<int> ans;
    vector<vector<int>> subsets;

    sort(nums.begin(), nums.end());

    allSubsets(nums, ans, 0, subsets);

    cout << "All subsets:" << endl;
    for (auto &subset : subsets)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}