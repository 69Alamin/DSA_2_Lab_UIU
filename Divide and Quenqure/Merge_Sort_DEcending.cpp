#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[],int low,int mid,int high){
    int left_index=low;
    int right_index=mid+1;
    
    int new_Arr[high-low+1];                    //for make a sorted subarray coppy
    int k=0;
    while(left_index<=mid&&right_index<=high){    
        if(arr[left_index]>arr[right_index]){    //check and insert item in new arry in sorted form
            new_Arr[k]=arr[left_index];
            k++;
            left_index++;
        }
        else{
            new_Arr[k]=arr[right_index];
            k++;
            right_index++;
        }
    }

    if(left_index>mid){                           
        for(int p=right_index;p<=high;p++){       //if right sub array has element 
            new_Arr[k]=arr[p];
            k++;
        }
    }

    if(right_index>high){
        for(int p=left_index;p<=mid;p++){         //if left sub array has element left 
            new_Arr[k]=arr[p];                    //just copide
            k++;
        }

    }

    for(int i=low,j=0;i<=high;i++,j++){          //simply paste all the sorted element in th main array from
        arr[i]=new_Arr[j];                       // new array
    }


}

void Msort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        Msort(arr,low,mid);
        Msort(arr,mid+1,high);
        Merge(arr,low,mid,high);

    }
}

int main() {
    int arr[]={9,8,7,5,6,4,9,2,1};
    int len=sizeof(arr)/sizeof(arr[0]);
    Msort(arr,0,len-1);

    for(int i=0;i<len;i++){
        cout<<arr[i]<<"  ";
    }
  
    
    return 0;
}