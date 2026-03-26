// TODO: Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

// *Example 1:
// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.

// *Example 2:
// Input: grid = [[3,2],[1,0]]
// Output: 0

// ? Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// -100 <= grid[i][j] <= 100
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    int row = grid.size();
    int cnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] < 0)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}