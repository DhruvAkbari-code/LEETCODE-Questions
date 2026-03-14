// TODO: Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// TODO: The overall run time complexity should be O(log (m+n)).

// *Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

//* Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

//? Constraints:
// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

// ! NOT DONE YET
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums1 = {2, 2, 4, 4};
    vector<int> nums2 = {2, 2, 2, 4, 4};
    int n1 = nums1.size();
    int n2 = nums2.size();
    double sum = 0;

    for (int i = 0; i < n1; i++)
    {
        sum += nums1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        sum += nums2[i];
    }
    cout << sum / (n1 + n2);
    return 0;
}