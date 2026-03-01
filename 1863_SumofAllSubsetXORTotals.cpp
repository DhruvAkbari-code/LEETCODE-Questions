// TODO: The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
// TODO: For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
// TODO: Given an array nums, return the sum of all XOR totals for every subset of nums.
// TODO: Note: Subsets with the same elements should be counted multiple times.
// TODO: An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

// *Example 1:
// *Input: nums = [1,3]
// *Output: 6
// *Explanation: The 4 subsets of [1,3] are:
// *- The empty subset has an XOR total of 0.
// *- [1] has an XOR total of 1.
// *- [3] has an XOR total of 3.
// *- [1,3] has an XOR total of 1 XOR 3 = 2.
// *0 + 1 + 3 + 2 = 6

// *Example 2:
// *Input: nums = [5,1,6]
// *Output: 28
// *Explanation: The 8 subsets of [5,1,6] are:
// *- The empty subset has an XOR total of 0.
// *- [5] has an XOR total of 5.
// *- [1] has an XOR total of 1.
// *- [6] has an XOR total of 6.
// *- [5,1] has an XOR total of 5 XOR 1 = 4.
// *- [5,6] has an XOR total of 5 XOR 6 = 3.
// *- [1,6] has an XOR total of 1 XOR 6 = 7.
// *- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
// *0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28

// *Example 3:
// *Input: nums = [3,4,5,6,7,8]
// *Output: 480
// *Explanation: The sum of all XOR totals for every subset is 480.

//? Constraints:
//? 1 <= nums.length <= 12
//? 1 <= nums[i] <= 20

// ! ChatGPT Code
/* #include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> nums = {1, 3};
    // vector<int> nums = {5, 1, 6};
    vector<int> nums = {3, 4, 5, 6, 7, 8};

    int n = nums.size();
    int total = 0;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        int subsetXor = 0;

        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                subsetXor ^= nums[i];
            }
        }

        total += subsetXor;
    }

    cout << total << endl;

    return 0;
}
 */

// ! leetCode Code
class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        vector<vector<int>> subsets;
        // Generate all of the subsets
        generateSubsets(nums, 0, {}, subsets);

        // Compute the XOR total for each subset and add to the result
        int result = 0;
        for (auto &subset : subsets)
        {
            int subsetXORTotal = 0;
            for (int num : subset)
            {
                subsetXORTotal ^= num;
            }
            result += subsetXORTotal;
        }
        return result;
    }

private:
    void generateSubsets(const vector<int> &nums, int index, vector<int> subset,
                         vector<vector<int>> &subsets)
    {
        // Base case: index reached end of nums
        // Add the current subset to subsets
        if (index == nums.size())
        {
            subsets.push_back(subset);
            return;
        }

        // Generate subsets with nums[i]
        subset.push_back(nums[index]);
        generateSubsets(nums, index + 1, subset, subsets);
        subset.pop_back();

        // Generate subsets without nums[i]
        generateSubsets(nums, index + 1, subset, subsets);
    }
};