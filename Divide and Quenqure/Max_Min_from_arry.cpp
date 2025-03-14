#include <bits/stdc++.h>
using namespace std;

struct result
{
    int max;
    int min;
};

result Max_Min(int arr[], int low, int high)
{
    if (low == high)
    {
        result f;
        f.max = arr[low];
        f.min = arr[low];
        return f;
    }
    else
    {
        int mid = (low + high) / 2;
        result r1 = Max_Min(arr, low, mid);
        result r2 = Max_Min(arr, mid + 1, high);

        result final;
        final.max = max(r1.max, r2.max);
        final.min = min(r1.min, r2.min);

        return final;
    }
}

int main()
{
    int Arr[] = {10, 5, 8, 9, 6, 21, 7, 6};
    int len = sizeof(Arr) / sizeof(Arr[0]);
    result cc=Max_Min(Arr,0,len-1);
    cout<<"Maximum "<<cc.max<<"  Minimum "<<cc.min;

    return 0;
}