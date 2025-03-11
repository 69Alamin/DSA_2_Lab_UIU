#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int main() {
    
    vector<pair<int,int>>pairs={{1,2},{5,6},{1,9},{6,8}};   //pair store 2 data 

    sort(pairs.begin(),pairs.end());  // Sorts by first element, then second (default behavior)
    for(auto &a:pairs){
        cout<<a.first<<" "<<a.second<<endl;
    }
    
    cout<<"Sorting by second"<<endl;
    sort(pairs.begin(),pairs.end(),comp);  // Sorts by second element
    for(auto &a:pairs){
        cout<<a.first<<" "<<a.second<<endl;
    }
    return 0;
}