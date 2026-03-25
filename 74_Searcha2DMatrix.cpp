// TODO: You are given an m x n integer matrix matrix with the following two properties:
// TODO: Each row is sorted in non-decreasing order.
// TODO: The first integer of each row is greater than the last integer of the previous row.
// TODO: Given an integer target, return true if target is in matrix or false otherwise.
// TODO: You must write a solution in O(log(m * n)) time complexity.

// * Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// * Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// ? Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

#include <iostream>
#include <vector>
using namespace std;

bool searchTarget(vector<vector<int>> mat, int target, int midRow)
{
    int n = mat[0].size();
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target == mat[midRow][mid])
        {
            return true;
        }
        else if (target > mat[midRow][mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 38;
    int row = mat.size(), col = mat[0].size();

    int startrow = 0, endRow = row - 1;

    while (startrow <= endRow)
    {
        int midRow = startrow + (endRow - startrow) / 2;
        if (target >= mat[midRow][0] && target <= mat[midRow][col - 1])
        {
            bool result = searchTarget(mat, target, midRow);
            cout << (result ? "true" : "false") << endl;
            return 0;
        }
        else if (target > mat[midRow][col - 1])
        {
            startrow = midRow + 1;
        }
        else
        {
            endRow = midRow - 1;
        }
    }

    return 0;
}