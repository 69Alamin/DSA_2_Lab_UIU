#include <bits/stdc++.h>
using namespace std;

int Sum_of_Digits(int n){
    if(n==0) return 0;

    return (n%10)+Sum_of_Digits(n/10);
}

int main() {
    
    int n;
    cin>>n;
    cout<<Sum_of_Digits(n);
    
    return 0;
}