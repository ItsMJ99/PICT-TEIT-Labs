// time complexity = o(N!)
// space complexity = O(N^2)

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n)
{
    int storeCol = col;
    int storeRow = row;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    row = storeRow;
    col = storeCol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = storeRow;
    col = storeCol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void printBoard(vector<string> &board)
{
    for (const string &row : board)
    {
        cout << "|";
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            // Print the board after placing a Queen
            cout << "Placing Queen at (" << row << ", " << col << ")" << endl;
            printBoard(board);

            solve(col + 1, board, ans, n);

            // Backtracking: Reset the cell to empty
            board[row][col] = '.';
            cout << "Backtracking from (" << row << ", " << col << ")" << endl;
            printBoard(board);
        }
    }
}

void solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans, n);

    int op = ans.size();
    if (op > 5)
        op = 5;

    for (int i = 0; i < op; i++)
    {
        cout << "Solution " << i + 1 << ":\n";
        for (int j = 0; j < n; j++)
        {
            cout << "|";
            for (int k = 0; k < n; k++)
            {
                if (ans[i][j][k] == 'Q')
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << "|" << endl;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of Queens : ";
    cin >> n;
    solveNQueens(n);
    return 0;
}
