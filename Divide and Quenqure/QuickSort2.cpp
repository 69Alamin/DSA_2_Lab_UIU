#include <bits/stdc++.h>
using namespace std;

int Partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(pivot>=arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;

}


void QuickSort(int arr[],int low,int high){
    if(low<high){
        int mid=Partition(arr,low,high);
        QuickSort(arr,low,mid-1);
        QuickSort(arr,mid+1,high);
    }
}

int main() {
    int arr[]={9,8,7,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,len-1);

    for(int i=0;i<len;i++){
        cout<<arr[i]<<"  ";
    }
    
    
    return 0;
}