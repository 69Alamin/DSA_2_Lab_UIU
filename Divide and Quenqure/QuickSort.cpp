#include <bits/stdc++.h>
using namespace std;

void QuicSort(int arr[],  int low, int high)
{
    if (low < high) {
        int pivot = low;
        int i = pivot + 1;
        int j = high;
        while (i <= j)
        {
            while (i <= j&&arr[pivot] > arr[i])
            {
                i++;
            }

            while (i <= j&&arr[pivot] < arr[j])
            {
                j--;
            }
            if (i <=j){
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
                
        }

        swap(arr[pivot],arr[j]);

        QuicSort(arr,low,j);
        QuicSort(arr,j+1,high);
    }
}

int main()
{
    int arr[]={9,8,7,5,6,4,2,0};
    int len=sizeof(arr)/sizeof(arr[0]);
    QuicSort(arr,0,len-1);

    for(int i=0;i<len;i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}