// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     vector<int> nums = {2, 2, 2, 2, 1, 1, 1};
//     int n = nums.size();
//     int cnt;
//     for (int i : nums)
//     {
//         cnt = 0;
//         for (int j : nums)
//         {
//             if (i == j)
//             {
//                 cnt++;
//             }
//         }
//         if (cnt > n / 2)
//         {
//             cout << i;
//             break;
//         }
//     }

//     return 0;
// }

// more modified way to do
// MOORE's algorithm
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {1, 1, 2, 2, 2, 2, 1, 1, 1};
    int n = nums.size();
    int freq = 0, ans;

    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        if (nums[i] == ans)
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    cout << ans;

    return 0;
}