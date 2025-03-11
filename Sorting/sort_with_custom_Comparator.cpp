#include <bits/stdc++.h>
using namespace std;

bool comparetor(int a,int b){
    if(a>b)
       return 1;
       else 
       return 0;

       //return a>b
}

int main() {
    
    vector<int> vec={10,5,6,9,25,8,1,0};
    sort (vec.begin(),vec.end(),comparetor);    // comparetor not incule any parameter 

    for(int i:vec){
        cout<<i<<" ";
    }
    
    return 0;
}