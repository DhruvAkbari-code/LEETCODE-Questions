// TODO: Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// TODO: There is only one repeated number in nums, return this repeated number.
// TODO: You must solve the problem without modifying the array nums and using only constant extra space.

//* Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2

//* Example 2:
// Input: nums = [3,1,3,4,2]
// Output: 3

//* Example 3:
// Input: nums = [3,3,3,3,3]
// Output: 3

//? Constraints:
// 1 <= n <= 105
// nums.length == n + 1
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer which appears two or more times.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    //! Method 1 to solve
    // unordered_set<int> s;
    // for(int i = 0; i < nums.size(); i++){
    //     if(s.find(nums[i]) != s.end()){
    //         cout<< nums[i];
    //     }
    //     s.insert(nums[i]);
    // }
    // return 0;

    //! Method 2 to solve
    // int n = nums.size();
    // vector<int> freq(n, 0);

    // for (int i = 0; i < n; i++)
    // {
    //     freq[nums[i]]++;
    //     if (freq[nums[i]] == 2)
    //     {
    //         cout << nums[i];
    //     }
    // }
    // return 0;

    //! Method 3 to solve with constant extra space
    int slow = nums[0], fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

    } while (slow != fast);

    slow = nums[0];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    cout << slow;

    return 0;
}