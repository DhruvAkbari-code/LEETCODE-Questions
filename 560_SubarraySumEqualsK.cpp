// TODO: Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// TODO: A subarray is a contiguous non-empty sequence of elements within an array.

//* Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

//* Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2

//? Constraints:
// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2, n = nums.size(), cnt = 0;

    // !Brute Force
    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += nums[j];
    //         if (sum == k)
    //         {
    //             cnt++;
    //         }
    //     }
    // }
    // cout << cnt;

    // ! Optimal
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    unordered_map<int, int> m;
    for (int j = 0; j < n; j++)
    {
        if (prefixSum[j] == k)
            cnt++;
        int val = prefixSum[j] - k;

        if (m.find(val) != m.end())
        {
            cnt += m[val];
        }

        if (m.find(prefixSum[j]) != m.end())
        {
            m[prefixSum[j]] = 0;
        }

        m[prefixSum[j]]++;
    }
    cout << cnt;

    return 0;
}