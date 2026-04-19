// TODO: Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

// *Example 1:
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]

// *Example 2:
// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4]

// ?Constraints:
// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// -105 <= mat[i][j] <= 105

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    if (mat.empty() || mat[0].empty())
        return {};

    int m = mat.size(), n = mat[0].size();
    int row = 0, col = 0;
    vector<int> ans(m * n);
    for (int i = 0; i < m * n; i++)
    {
        ans[i] = mat[row][col];
        if ((row + col) % 2 == 0)
        {
            if (col == n - 1)
                row++;
            else if (row == 0)
                col++;
            else
            {
                row--;
                col++;
            }
        }
        else
        {
            if (row == m - 1)
                col++;
            else if (col == 0)
                row++;
            else
            {
                row++;
                col--;
            }
        }
    }

    for (int n : ans)
    {
        cout<<n;
    }
    return 0;
}
