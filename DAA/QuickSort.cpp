#include <iostream>
#include <algorithm>
using namespace std;

int partition(int a[], int start, int end)
{
    int piv = a[start];
    int beg = start;
    start += 1;
    while (start <= end)
    {
        if (a[start] >= piv && a[end] <= piv)
        {
            swap(a[start], a[end]);
            start++;
            end--;
        }
        if (a[start] < piv)
            start++;
        if (a[end] > piv)
            end--;
    }
    swap(a[beg], a[end]);
    return end;
}

void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int p = partition(a, start, end);
        quickSort(a, start, p - 1);
        quickSort(a, p + 1, end);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}