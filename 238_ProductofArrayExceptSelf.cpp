// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

// ! Simple Calculation
/* #include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    vector<int> ans;
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    suffix[n - 1] = 1;

    for (int i = 1; i < n; i++)
    {
        prefix[i] = (prefix[i - 1] * nums[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = (suffix[i + 1] * nums[i + 1]);
    }
    for (int k = 0; k < n; k++)
    {
        ans.push_back(prefix[k] * suffix[k]);
    }

    return 0;
} */

// ! Most Optimal Solution
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();

    vector<int> ans(n, 1);
    int prefix = 1, suffix = 1;

    int i = 0, j = n - 1;
    while (i < n)
    {
        ans[i] *= prefix;
        ans[j] *= suffix;

        prefix *= nums[i];
        suffix *= nums[j];

        i++;
        j--;
    }

    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
