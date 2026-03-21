// TODO: Given an integer n, return the number of prime numbers that are strictly less than n.

// *Example 1:
// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

// *Example 2:
// Input: n = 0
// Output: 0

// *Example 3:
// Input: n = 1
// Output: 0

// ? Constraints:
// 0 <= n <= 5 * 106

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 10;
    int ans = 0;
    vector<bool> isPrime(n + 1, true);

    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            ans++;
            for (int j = i * 2; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    cout << ans;
    return 0;
}