#include <bits/stdc++.h>
using namespace std;

int nCr(int n,int r){
    if(r==n||r==0) return 1;        // nC0 = 1, nCn = 1
    if(r>n) return 0;              // If r > n, result is 0
    return nCr(n-1,r)+nCr(n-1,r-1);
}

int main() {
    
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r);
    
    return 0;
}