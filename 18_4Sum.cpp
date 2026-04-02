// TODO: Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// TODO: 0 <= a, b, c, d < n
// TODO: a, b, c, and d are distinct.
// TODO: nums[a] + nums[b] + nums[c] + nums[d] == target
// TODO: You may return the answer in any order.

// *Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// *Example 2:
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

// ?Constraints:
// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n;)
        {
            int start = j + 1, end = n - 1;
            while (start < end)
            {
                long long sum = (long long)nums[i] + (long long)nums[j] +
                                (long long)nums[start] + (long long)nums[end];
                if (sum > target)
                {
                    end--;
                }
                else if (sum < target)
                {
                    start++;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                    start++;
                    end--;
                    while (start < end && nums[start] == nums[start - 1])
                        start++;
                }
            }
            j++;
            while (j < n && nums[j] == nums[j - 1])
                j++;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}