#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int arr[]={10,12,1,5,2,5,6,2,20,4};
    int len =sizeof(arr)/sizeof(arr[0]);
    
    //Acending sort
    sort(arr,arr+len);                   //    sort() sorts elements in the range [arr, arr + len), 
                                         //    meaning it includes arr (the first element) but excludes arr + len
                                         //    (one past the last element).
    
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

    sort(arr,arr+len,greater<int>());    //decending sort
    for(int i:arr){
        cout<<i<<" ";
    }
    

    

    return 0;
}