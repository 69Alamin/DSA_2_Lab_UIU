#include <bits/stdc++.h>
using namespace std;

int sum_of_Even(int arr[], int low, int high)
{
    if (low == high)
    {
        if (arr[low] % 2 == 0)
            return arr[low];

        return 0;
    }

    else
    {
        int mid = (low + high) / 2;
        int sum1 = sum_of_Even(arr, low, mid);
        int sum2 = sum_of_Even(arr, mid + 1, high);

        return sum1 + sum2;
    }
}

int main()
{
    int Arr[] = {10, 5, 8, 9, 6, 21, 7, 6};
    int len = sizeof(Arr) / sizeof(Arr[0]);
    cout << sum_of_Even(Arr, 0, len - 1);

    return 0;
}