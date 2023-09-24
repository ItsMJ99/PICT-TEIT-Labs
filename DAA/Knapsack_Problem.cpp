#include <iostream>
using namespace std;

int n;
float capacity;

struct item
{
    float ratio;
    float weight;
    float profit;
};

void display(struct item s[])
{
    for (int i = 0; i < n; i++)
        cout << "\nRatio : " << s[i].ratio << " Profit :" << s[i].profit << " Weight : " << s[i].weight << endl;
}

int partition(item arr[], int start, int end)
{
    item pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i].ratio >= pivot.ratio)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i].ratio >= pivot.ratio)
            i++;
        while (arr[j].ratio < pivot.ratio)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(item arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void fill(struct item s[])
{
    float bag = 0;
    float ans;
    for (int i = 0; i < n; i++)
    {
        if (bag < capacity)
        {
            if (bag + s[i].weight > capacity)
            {
                float rem = capacity - bag;
                ans += (rem / s[i].weight) * s[i].profit;
                bag += rem;
                cout << "\nCurrent profit : " << ans << " Current bag weight : " << bag << endl;
                break;
            }
            else
            {
                ans += s[i].profit;
                bag += s[i].weight;
            }
        }
        cout << "\nCurrent profit : " << ans << " Current bag weight : " << bag << endl;
    }
    cout << "\nFinal Answer\n"
         << "\nprofit : " << ans << " bag weight : " << bag << endl;
}

int main()
{
    cout << "Enter the Number of Items : ";

    item it[5];
    cin >> n;
    cout << "Enter Capacity : ";
    cin >> capacity;

    for (int i = 0; i < n; i++)
    {
        cin >> it[i].profit;
        cin >> it[i].weight;
        it[i].ratio = it[i].profit / it[i].weight;
        cout << it[i].ratio;
    }
    quickSort(it, 0, n - 1);
    display(it);
    fill(it);
    // MENU:
    //     int ch;
    //     cout << "==========[ MENU ]==========" << endl;
    //     cout << "\n0. Exit\n1. Greedy Approach\n2. 0/1 Approach" << endl;
    //     cout << "Enter Choice : ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 0:
    //         exit;
    //     case 1:
    //         display(it);
    //         fill(it);
    //         goto MENU;
    //     case 2:
    //         goto MENU;
    //     }
    return 0;
}
