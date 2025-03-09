#include <bits/stdc++.h>
using namespace std;

int power(int x,int y){
    if(y==1||y==0)return x;

    return x*power(x,y-1);

}

int main() {
    
    int x,y;
    cin>>x>>y;
    cout<<power(x,y);
    
    return 0;
}