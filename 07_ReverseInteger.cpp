// TODO: Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// TODO: Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// *Example 1:
// Input: x = 123
// Output: 321

// *Example 2:
// Input: x = -123
// Output: -321

// *Example 3:
// Input: x = 120
// Output: 21

// ? Constraints:
// -231 <= x <= 231 - 1\

#include <iostream>
using namespace std;
int main()
{
    int n = 123, temp = 0;
    int revNum = 0;
    while (n != 0)
    {
        temp = n % 10;
        if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10)
        {
            return 0;
        }
        revNum = revNum * 10 + temp;
        n /= 10;
    }
    cout << revNum;
    return 0;
}
