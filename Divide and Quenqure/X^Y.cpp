#include <bits/stdc++.h>
using namespace std;

long long power(long  x,long y){
    if(y==0) return 1;
    else{
        long long half=power(x,y/2);
        if(y%2==0) return half*half;
        else return half*half*x;
    }
}

int main() {
    
    int x,y;
    cin>>x>>y;
    cout<<power(x,y);
    
    return 0;
}