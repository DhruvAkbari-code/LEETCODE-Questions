// TODO: Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.
// TODO: Return the sum of the three integers.
// TODO: You may assume that each input would have exactly one solution.

//* Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

//* Example 2:
// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

//? Constraints:
// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < nums.size(); i++)
    {
        int start = i + 1, end = nums.size() - 1;
        while (start < end)
        {
            int sum = nums[i] + nums[start] + nums[end];
            if (abs(sum - target) < abs(ans - target))
            {
                ans = sum;
            }
            if (sum < target)
            {
                start++;
            }
            else if (sum > target)
            {
                end--;
            }
            else
            {
                cout << sum;
            }
        }
    }
    cout << ans;

    return 0;
}