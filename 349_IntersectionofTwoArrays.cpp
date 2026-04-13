// TODO: Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

// *Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]

// *Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.

// ?Constraints:
// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> result;

    for (int num : nums2)
    {
        if (set1.count(num))
        {
            result.insert(num);
        }
    }

    vector<int> ans = vector<int>(result.begin(), result.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }

    return 0;
}