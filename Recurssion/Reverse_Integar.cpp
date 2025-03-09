#include <bits/stdc++.h>
using namespace std;

int reverse(int n,int rev){
   if(n==0) return rev;

   rev=rev*10;
   rev+=n%10;

   return reverse(n/10,rev);
}

int main() {
    
    int n;
    cin>>n;
    cout<<reverse(n,0);
    
    return 0;
}