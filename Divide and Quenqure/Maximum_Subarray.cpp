#include <bits/stdc++.h>
using namespace std;

struct result
{
    int left, right, sum = 0;
};

result Crosssum(int arr[], int low, int mid, int high)
{

    int sum = 0;
    int leftsum = INT_MIN;
    int maxleft=mid;
    for (int i = mid; i >= low; i--)
    {

        sum += arr[i];
        if (sum > leftsum)
        {
            leftsum = sum;
            maxleft = i;
        }
    }

    sum = 0;
    int rightsum =INT_MIN;
    int maxright=mid+1;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > rightsum)
        {
            rightsum = sum;
            maxright = i;
        }
    }

    return {maxleft, maxright, rightsum + leftsum};
}

result MaximunSubarray(int arr[], int low, int high)
{
    if (low == high)
        return {low, low, arr[low]};

    else
    {
        int mid = (low + high) / 2;
        result leftsub = MaximunSubarray(arr, low, mid);
        result rightsub = MaximunSubarray(arr, mid + 1, high);
        result cross = Crosssum(arr, low, mid, high);

        if (leftsub.sum >= rightsub.sum && leftsub.sum >= cross.sum)
            return leftsub;

        else if (rightsub.sum >= leftsub.sum && rightsub.sum >= cross.sum)
            return rightsub;

        else
            return cross;
    }
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    result final_rsult= MaximunSubarray(arr, 0, len - 1);

    for (int i =final_rsult.left; i <=final_rsult.right; i++)
    {
        cout << arr[i] << "  ";
    }
    cout<<final_rsult.sum<<endl;

    return 0;
}