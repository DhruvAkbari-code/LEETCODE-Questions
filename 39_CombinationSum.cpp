// TODO: Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// TODO: The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// TODO:  The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// *Example 1:
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// *Example 2:
// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// *Example 3:
// Input: candidates = [2], target = 1
// Output: []

// ?Constraints:
// 1 <= candidates.length <= 30
// 2 <= candidates[i] <= 40
// All elements of candidates are distinct.
// 1 <= target <= 40

#include <iostream>
#include <vector>
using namespace std;
void getAllCombination(vector<int> &nums, int idx, int target, vector<vector<int>> &ans, vector<int> &combin)
{
    if (idx == nums.size() || target < 0)
    {
        return;
    }

    if (target == 0)
    {
        ans.push_back(combin);
        return;
    }
    combin.push_back(nums[idx]);
    getAllCombination(nums, idx, target - nums[idx], ans, combin);
    combin.pop_back();
    getAllCombination(nums, idx + 1, target, ans, combin);
}
int main()
{
    vector<int> nums = {2, 3, 5};
    vector<int> combin;
    vector<vector<int>> ans;
    int target = 8;
    getAllCombination(nums, 0, target, ans, combin);

    for (auto &n : ans)
    {
        for (int i = 0; i < n.size(); i++)
        {
            cout << n[i];
        }
        cout << endl;
    }
    return 0;
}