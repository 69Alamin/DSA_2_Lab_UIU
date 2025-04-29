#include <bits/stdc++.h>
using namespace std;



struct activity
{
    double id,start,end;
};


vector<activity>selected;

bool comp(activity a,activity b){
    return a.end<b.end;
}

void Greedy_Activity_Selector(vector<activity>activities,int n){
    sort(activities.begin(),activities.end(),comp);
     
    int last_selected=0;
    selected.push_back(activities[last_selected]);
    int i=1;
    while (i<n)
    {  if(activities[i].start>=activities[last_selected].end){
            selected.push_back(activities[i]);
            last_selected=i;
        }
        
        i++;
    }
    

}


int main() {
    
    int n;
    cin>>n;
    vector<activity>activities(n);
    for(int i=0;i<n;i++ ){
        activities[i].id=i+1;
        cin>>activities[i].start>>activities[i].end;

    }

    Greedy_Activity_Selector(activities,n);

    cout<<"Maximum Activity"<<selected.size()<<endl;
    for(auto a:selected){
        cout<<a.id<<" : "<<a.start<<"--"<<a.end<<endl;
    }
    
    
    return 0;
}