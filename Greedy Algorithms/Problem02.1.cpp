#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct club{
   char id;
   int start,duration;
};

bool compare(club a,club b){
     return b.duration>a.duration;
}

vector<char>Maximum_events(vector<club>clubs,int n,int cleantime){
    int endtime=0;
    for(int i=0;i<n;i++){
        endtime=clubs[i].start+clubs[i].duration+cleantime;
        clubs[i].duration=endtime;
        //cout<<endtime<<endl;
    }

    sort(clubs.begin(),clubs.end(),compare);

    vector<char>res;
    res.push_back(clubs[0].id);
    int last_selected=clubs[0].duration;
    for(int i=1;i<n;i++){
        if(clubs[i].start>=last_selected){
            res.push_back(clubs[i].id);
            last_selected=clubs[i].duration;
        }

    }
    return res;


}

int main()
{
    int n;
    cin>>n;
    vector<club>clubs(n);
    for(int i=0;i<n;i++){
        cin>>clubs[i].id>>clubs[i].start>>clubs[i].duration;
    }

    int clean;
    cin>>clean;

    vector<char>selected=Maximum_events(clubs,n,clean);
    if(!selected.empty()){
            cout<<"Chosen clubs :"<<endl;
        for(int i=0;i<selected.size();i++){
            cout<<selected[i]<<endl;
        }
    }

    return 0;
}