#include <bits/stdc++.h>
using namespace std;

void Binary_Search(int arr[], int low, int high, int target)
{
    if (low > high)
    {
        cout << target << "  Not found";
        return;
    }

    int mid = (low + high) / 2;

    if (target == arr[mid])
    {
        cout << target << " found in index " << mid;
        return ;
    }
    else if (target < arr[mid])
        Binary_Search(arr, low, mid-1, target);
    else
        Binary_Search(arr, mid + 1, high, target);
}

int main()
{
    int n;
    cout << "Size of array :";
    cin >> n;
    int arr[n];
    int i = 0;
    while (i < n)
    {
        cin >> arr[i];
        i++;
    }

    sort(arr, arr + n);    //accending sort

    int target;
    cout << "Target :";
    cin >> target;
    Binary_Search(arr, 0, n-1, target);

    return 0;
}