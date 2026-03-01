// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int index;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            index = i;
            break;
        }
        else
        {
            if (nums[i] > target)
            {
                index = i;
                break;
            }
        }
    }
    cout << index;

    return 0;
}
