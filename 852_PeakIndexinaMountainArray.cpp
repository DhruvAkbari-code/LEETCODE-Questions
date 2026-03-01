// TODO: You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
// TODO: Return the index of the peak element.
// TODO: Your task is to solve it in O(log(n)) time complexity.

// *Example 1:
// Input: arr = [0,1,0]
// Output: 1

// *Example 2:
// Input: arr = [0,2,1,0]
// Output: 1

// *Example 3:
// Input: arr = [0,10,5,2]
// Output: 1

// ?Constraints:
// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.

//! Linear way to do it
/* #include <iostream>
#include <vector>
using namespace std;
int main()
{
    // vector<int> nums = {0, 3, 8, 9, 5, 2};
    vector<int> nums = {0, 1, 0};
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
        {
            cout << i;
        }
    }

    return 0;
} */

//! Binary Search
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // vector<int> arr = {0, 3, 8, 9, 5, 2};
    vector<int> arr = {3, 5, 3, 2, 0};
    int n = arr.size();
    int start = 1, end = n - 2;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        cout << "Start : " << start << " End : " << end << " Mid : " << mid << endl;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            cout << mid;
        }
        if (arr[mid - 1] < arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return 0;
}