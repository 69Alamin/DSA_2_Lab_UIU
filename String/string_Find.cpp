#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string st="Yes,we went to gate after we close the dorm";
    int first_we=st.find("we");   //find first we
    int sec_we=st.find("we",first_we+1);   //key=we and start from 5 index
    int third_we=st.find("we",sec_we+1);
    cout<<first_we<<endl;
    cout<<sec_we<<endl;
    cout<<third_we<<endl;

    int qPos=st.find("Alamin");     //if not found retun   string::npos
    cout<<((qPos!=string::npos)?"Yes":"No"); 
    
    return 0;
}