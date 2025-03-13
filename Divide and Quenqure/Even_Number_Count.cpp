#include <bits/stdc++.h>
using namespace std;

int countEven(int Arr[],int i,int j){
    if(i==j){
        if(Arr[i]%2==0)return 1;
        else return 0;
    }
    else{
        int mid=(i+j)/2;
        int c1=countEven(Arr,i,mid);
        int c2=countEven(Arr,mid+1,j);
        return c1+c2;
    }
}


int main() {
    
    int Arr[]={10,5,8,9,6,21,7,6};
    int len=sizeof(Arr)/sizeof(Arr[0]);
    cout<<countEven(Arr,0,len-1);
    
    return 0;
}