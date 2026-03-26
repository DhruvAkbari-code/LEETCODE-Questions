// TODO: Given an m x n matrix, return all elements of the matrix in spiral order.

// * Example 1:
// Input: matrix = {{1,2,3},[4,5,6},[7,8,9}]
// Output: [1,2,3,6,9,8,7,4,5]

// * Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// ? Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> matrix;
    int row = mat.size(), col = mat[0].size();

    int srow = 0, scol = 0, erow = row - 1, ecol = col - 1;

    while (srow <= erow && scol <= ecol)
    {
        for (int j = scol; j <= ecol; j++)
        {
            matrix.push_back(mat[srow][j]);
        }

        for (int k = srow + 1; k <= erow; k++)
        {
            matrix.push_back(mat[k][ecol]);
        }

        for (int l = ecol - 1; l >= scol; l--)
        {
            if (srow == erow)
            {
                break;
            }
            matrix.push_back(mat[erow][l]);
        }

        for (int m = erow - 1; m >= srow + 1; m--)
        {
            if (scol == ecol)
            {
                break;
            }
            matrix.push_back(mat[m][scol]);
        }

        srow++;
        erow--;
        scol++;
        ecol--;
    }

    for (int print : matrix)
    {
        cout << print;
    }
    return 0;
}
