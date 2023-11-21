// Time Complexity O(n * cap)
// Space Complexity O(n * cap)

#include <iostream>
using namespace std;

struct item
{
    int id;
    int profit;
    int weight;
};

void zeroOneKnapsack(struct item it[], int n)
{
    int cap;
    cout << "\nEnter the Bag Capacity : ";
    cin >> cap;
    int matrix[n + 1][cap + 1];
    for (int r = 0; r <= n; r++)
    {
        for (int c = 0; c <= cap; c++)
        {
            if (r == 0 || c == 0)
                matrix[r][c] = 0;
            else if (c - it[r].weight >= 0)
            {
                matrix[r][c] = max(matrix[r - 1][c], (matrix[r - 1][c - it[r].weight]) + it[r].profit);
            }
            else
                matrix[r][c] = matrix[r - 1][c];
        }
    }
    cout << "\n========== Matrix Formation ==========\n"
         << endl;
    for (int r = 0; r <= n; r++)
    {

        for (int c = 0; c <= cap; c++)
        {
            cout << matrix[r][c] << "\t";
        }
        cout << endl;
    }
    cout << "\nMaximum Profit : " << matrix[n][cap] << endl;
    cout << "\n\nBacktracking Started ................" << endl;
    int rw = n;
    int cl = cap;
    cout << "\nItems Selected : ";
    while (cl > 0 && rw > 0)
    {
        if (matrix[rw][cl] != matrix[rw - 1][cl])
        {
            cout << "Item " << it[rw].id << " ,";
            cl -= it[rw].weight;
            rw--;
        }
        else
            rw--;
    }
    cout << "\n\nBacktracking Finished ................" << endl;
}

int main()
{
    int n;
    cout << "Enter the number of Items : ";
    cin >> n;
    struct item it[n];
    for (int i = 1; i <= n; i++)
    {
        it[i].id = i;
        cout << "\nEnter Item " << i << " Profit : ";
        cin >> it[i].profit;
        cout << "Enter Item " << i << " weight : ";
        cin >> it[i].weight;
    }
    zeroOneKnapsack(it, n);
    return 0;
}
