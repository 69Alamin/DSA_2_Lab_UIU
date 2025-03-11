#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string st="My name is Alamin ,I am a student of UIU";
    cout<<st<<endl;
    int found=st.find(",");
    string new_str=st.substr(0,found);  // start from 0 index and end in found
    cout<<new_str<<endl;
     new_str+=st.substr(found+8);    //start from here and added upto last
         cout<<new_str<<endl;
    return 0;
}