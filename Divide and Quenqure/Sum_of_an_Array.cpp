#include <bits/stdc++.h>
using namespace std;

int sum_arr(int arr[], int low, int high)
{
    if (low == high)
        return arr[low];
    else
    {
        int mid = (low + high) / 2;
        int sum1 = sum_arr(arr, low, mid);
        int sum2 = sum_arr(arr, mid + 1, high);

        return sum1 + sum2;
    }
}

int main()
{
    int Arr[] = {10, 5, 8, 9, 6, 21, 7, 6};
    int len = sizeof(Arr) / sizeof(Arr[0]);
    cout << sum_arr(Arr, 0, len - 1);

    return 0;
}