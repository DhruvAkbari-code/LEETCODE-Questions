// TODO: Given an array of integers nums, return the number of good pairs.
// TODO: A pair (i, j) is called good if nums[i] == nums[j] and i < j.

//* Example 1:
// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

//* Example 2:
// Input: nums = [1,1,1,1]
// Output: 6
// Explanation: Each pair in the array are good.

//* Example 3:
// Input: nums = [1,2,3]
// Output: 0

//? Constraints:
// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    int start = 0;
    int sec = 1, end = nums.size() - 1;
    int cnt = 0;
    while (start < end)
    {
        if (sec > end)
        {
            start++;
            sec = start + 1;
        }
        else if (nums[start] == nums[sec])
        {
            cnt++;
            sec++;
        }
        else
        {
            sec++;
        }
    }
    cout << cnt;
    return 0;
}