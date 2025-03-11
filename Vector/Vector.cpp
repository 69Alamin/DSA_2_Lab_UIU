#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int>vec;
    vec.push_back(5);        //insert
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(25);

    //vec.pop_back();      //delete  the last element

   // vec.erase(vec.begin(),vec.begin()+2);       //delete a range 
   // vec.erase(find(vec.begin(),vec.end(),8));     //find a element and delete
    auto it =find(vec.begin(),vec.end(),10);     //Find a element and store a pointer 
                                                  // auto -> automatically identify datatype and store
    for(int i=0;i<vec.size();i++){
        cout<<vec.at(i)<<endl;
    }
    cout<<*it;
    
    return 0;
}