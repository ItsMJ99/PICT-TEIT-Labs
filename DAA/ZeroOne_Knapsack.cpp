#include <iostream>
using namespace std;

struct item
{
    int profit;
    int weight;
};

void solveKnapsack(struct item it[], int n, int c)
{
    int matrix[n][c + 1];
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <= c; col++)
        {
            if (row == 0 || col == 0)
                matrix[row][col] = 0;
            else if ((col - it[row].weight) >= 0)
                matrix[row][col] = max(matrix[row - 1][col], (matrix[row - 1][col - it[row].weight]) + it[row].profit);
            else
                matrix[row][col] = matrix[row - 1][col];
        }
    }
    cout << "\nKnapsack Formation : \n"
         << endl;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <= c; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << "\nMax Profit : " << matrix[n - 1][c] << endl;

    cout << "Items Selected are :";
    int r = n - 1;
    while (c > 0 && r > 0)
    {
        if (matrix[r][c] != matrix[r - 1][c])
        {
            cout << " item " << r;
            c -= it[r].weight;
        }
        r--;
    }
}

int main()
{
    int n, capacity;
    cout << "Enter Number of Elements : ";
    cin >> n;
    cout << "Enter Sack Capacity : ";
    cin >> capacity;
    n += 1;
    item it[n];
    for (int i = 1; i <= n; i++)
    {
        cout << "Element " << i + 1 << " Profit : ";
        cin >> it[i].profit;
        cout << "Element " << i + 1 << " Weight : ";
        cin >> it[i].weight;
        cout << endl;
    }
    solveKnapsack(it, n, capacity);
    return 0;
}