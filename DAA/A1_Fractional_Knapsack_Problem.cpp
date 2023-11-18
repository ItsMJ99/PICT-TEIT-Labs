#include <iostream>
#include <algorithm>
using namespace std;

struct item
{
    int id;
    float ratio;
    float weight;
    float profit;
};

// Time complexity: O(n), Space complexity: O(1)
int partition(struct item it[], int start, int end)
{
    float piv = it[start].ratio;
    int beg = start;
    start += 1;
    while (start <= end)
    {
        if (it[start].ratio >= piv && it[end].ratio <= piv)
        {
            swap(it[start], it[end]);
            start++;
            end--;
        }
        if (it[start].ratio < piv)
        {
            start++;
        }
        if (it[end].ratio > piv)
        {
            end--;
        }
    }
    swap(it[beg], it[end]);
    return end;
}

// Time complexity: O(n log n), Space complexity: O(log n) (due to recursive call stack)
void quickSort(struct item it[], int start, int end)
{
    if (start < end)
    {
        int p = partition(it, start, end);
        quickSort(it, start, p - 1);
        quickSort(it, p + 1, end);
    }
}

// Time complexity: O(n log n) (due to sorting), Space complexity: O(1)
void fractionalKnapsack(struct item it[], int n)
{
    int bag = 0;
    float capacity;
    float p = 0;
    cout << "\nEnter the Bag Capacity : ";
    cin >> capacity;
    string ans = "";
    for (int i = n - 1; i >= 0; i--)
    {
        if (bag + it[i].weight <= capacity)
        {
            bag += it[i].weight;
            p += it[i].profit;
            ans += "Item " + to_string(it[i].id) + " ,";
            cout << "\nItem Selected : " << it[i].id << " with Profit : " << it[i].profit << " and weight : " << it[i].weight << "\nCurrent Bag Size : " << bag << "\tProfit : " << p << endl;
        }
        else if (bag + it[i].weight > capacity)
        {
            int rem = capacity - bag;
            bag += rem;
            p += (rem / it[i].weight) * it[i].profit;
            ans += "Item " + to_string(it[i].id);
            cout << "\nItem Selected : " << it[i].id << " with Fractional Profit : " << it[i].profit << " and Fractional weight : " << it[i].weight << "\nCurrent Bag Size : " << bag << "\tProfit : " << p << endl;
        }
        if (bag == capacity)
            break;
    }

    cout << "\n==========Final Answer==========\n"
         << endl;
    cout << "Items Selected are : " << ans;
    cout << "\nFinal Profit : " << p << endl;
}

// Time complexity: O(n log n) (due to sorting), Space complexity: O(n)
int main()
{
    int n;
    cout << "Enter the number of Items : ";
    cin >> n;
    struct item it[n];
    for (int i = 0; i < n; i++)
    {
        it[i].id = i + 1;
        cout << "\nEnter the item " << i + 1 << " Profit : ";
        cin >> it[i].profit;
        cout << "Enter the item " << i + 1 << " Weight : ";
        cin >> it[i].weight;
        it[i].ratio = it[i].profit / it[i].weight;
    }
    quickSort(it, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)
    {
        cout << "\nItem  : " << it[i].id << " with Profit : " << it[i].profit << " and weight : " << it[i].weight << " and Ratio : " << it[i].ratio << endl;
    }
    fractionalKnapsack(it, n);
    return 0;
}
