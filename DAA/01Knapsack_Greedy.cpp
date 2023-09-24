#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void knapsack(int n, int maxWeight, vector<int> &wt, vector<int> &profit)
{
    vector<pair<float, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        float pw_ratio = (float)profit[i] / wt[i];
        v.push_back({pw_ratio, {profit[i], wt[i]}});
    }
    sort(v.rbegin(), v.rend());
    cout << "Data in descending order" << endl;
    cout << "Profit:\t\t";
    for (auto it : v)
        cout << it.second.first << "\t";
    cout << endl;
    cout << "Weight:\t\t";
    for (auto it : v)
        cout << it.second.second << "\t";
    cout << endl;
    cout << "P/W ratio:\t";
    for (auto it : v)
        cout << it.first << "\t";
    cout << endl;
    cout << "=========================================" << endl;
    double finalProfit = 0;
    cout << "Knapsack filling begins .....\n"
         << endl;
    for (auto it : v)
    {
        if (maxWeight > 0 && it.second.second <= maxWeight)
        {
            cout << "weight : " << it.second.second << endl;
            cout << "Profit : " << it.second.first << endl;
            cout << endl;
            maxWeight = maxWeight - it.second.second;
            finalProfit = finalProfit + it.second.first;
        }
    }
    cout << "remaining weight : " << maxWeight << endl;
    cout << "Maximum profit obtained : " << finalProfit << endl;
}

int main()
{
    vector<int> weight;
    vector<int> profit;
    int n, capacity;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the Capacity of the bag : ";
    cin >> capacity;
    cout << "Enter the weights of the " << n << " items : " << endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        weight.push_back(temp);
    }
    cout << "Enter the profits of the " << n << " items : " << endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        profit.push_back(temp);
    }
    knapsack(n, capacity, weight, profit);
    return 0;
}