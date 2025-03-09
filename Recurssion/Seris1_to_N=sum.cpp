#include <bits/stdc++.h>
using namespace std;

int summation(int n){
    if(n==1) return 1;

    return n+summation(n-1);
}

int main() {
    
   int n;
   cin>>n;
   cout<<summation(n);
    
    return 0;
}