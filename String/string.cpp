#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string str1="Alamin";    //initialize
   // cout<<str1<<endl;

    char str[]="Alamin MIa";  //initialize c style
    string str2=string(str);  //convert into string
   // cout<<str2<<endl;
    
    //length of string
   // cout<<str1.length()<<endl;

    //accesing indivisual chracter
   // cout<<"str1[0]:"<<str1[0]<<endl;

    //append
    str1+="0";
    //cout<<str1<<endl;
    str1+=str2;
    //cout<<str1<<endl;

    //input
    string word,line;
    cin>>word;
    cout<<word<<endl;

    cin.sync();
    //input a full line
    getline(cin,line);
    cout<<line<<endl;


    getline(cin,line,'/');   //akta specific target porjonto input nibe ,here '/'
    cout<<line<<endl;
    
    return 0;
}