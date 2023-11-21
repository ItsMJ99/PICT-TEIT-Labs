// Time Complexity O(2 ^ n)
// Space Complexity O(n)

#include <iostream>
#include <vector>
using namespace std;

bool flag = 0;

void sumOfSubset(int i, int n, int target, vector<int> sets, vector<int> subsets)
{
    // targetSum is zero then there exists a subset
    if (target == 0)
    {
        // Prints valid subset
        flag = 1;
        cout << "[";
        for (int i = 0; i < subsets.size(); i++)
        {
            cout << subsets[i] << " ";
        }
        cout << "]" << endl;
        return;
    }

    // return if we have reached at the end of the array
    if (i == n)
        return;

    // current element not included
    sumOfSubset(i + 1, n, target, sets, subsets);

    // current element included
    if (sets[i] <= target)
    {
        subsets.push_back(sets[i]);
        sumOfSubset(i + 1, n, target - sets[i], sets, subsets);
        subsets.pop_back();
    }
}

int main()
{
    int n, target;
    cout << "Enter the Target Sum : ";
    cin >> target;
    cout << "Enter the number of elements in Sets : ";
    cin >> n;
    vector<int> sets(n);
    vector<int> subsets;
    for (int i = 0; i < n; i++)
    {
        cin >> sets[i];
    }
    sumOfSubset(0, n, target, sets, subsets);
    if (!flag)
    {
        cout << "There is no subset in this set !!!" << endl;
    }
    return 0;
}