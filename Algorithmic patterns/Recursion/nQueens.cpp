#include <bits/stdc++.h>
using namespace std;

bool issafe(int row, int col, vector<string> &board, int n)
{
    for (int i = 0; i != row; ++i)
        if (board[i][col] == 'Q')
            return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        if (board[i][j] == 'Q')
            return false;
    return true;
}

void helper(vector<vector<string>> &res, int n, int row, vector<string> &board)
{
    if (row == n)
    {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (issafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            helper(res, n, row + 1, board);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n = 4;
    vector<string> board(n);
    string str(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = str;
    vector<vector<string>> res;
    helper(res, n, 0, board);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < n; j++)
            cout << res[i][j] << endl;
        cout << endl;
    }
    return 0;
}