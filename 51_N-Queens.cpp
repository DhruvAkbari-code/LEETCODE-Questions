// TODO: Then-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// TODO: Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// TODO: Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

//* Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

//* Example 2:
// Input: n = 1
// Output: [["Q"]]

//? Constraints:
// 1 <= n <= 9

#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<string> &board, int row, int col, int n)
{
    for (int j = 0; j < n; j++)
        if (board[row][j] == 'Q')
            return false;
    for (int j = 0; j < n; j++)
        if (board[j][col] == 'Q')
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;
    return true;
}

void Queens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i, n))
        {
            board[row][i] = 'Q';
 
            board[row][i] = '.';
        }
    }
}
int main()
{
    int n = 4;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    Queens(board, 0, n, ans);

    for (auto &queen : ans)
    {
        cout << "[";
        for (int i = 0; i < queen.size(); i++)
        {
            cout << queen[i];
            if (i < queen.size() - 1)
                cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}