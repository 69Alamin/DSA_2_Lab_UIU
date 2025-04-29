#include <bits/stdc++.h>
using namespace std;

struct item
{   string name;
    double weight,value;
};

bool compare(item a,item b){
    return (1.0*a.value/a.weight)>(1.0*b.value/b.weight);
}

double Fractional_Knapsack(vector<item>&items,int n,double capacity){
   
    sort(items.begin(),items.end(),compare);
    double profit=0;
    int i=0;
    while (capacity>0 and i<n)
    {
        if(items[i].weight>0){

            if(capacity>=items[i].weight){
                cout<<"Taking "<<items[i].name<<" :"<<items[i].weight<<"  kg   "<<items[i].value<<" taka"<<endl;
                profit+=items[i].value;
                capacity-=items[i].weight;
                items[i].weight=0;
            }
            else {
                double fraction_profit = (items[i].value / items[i].weight) * capacity;
                profit += fraction_profit;
            
                cout << "Taking " << items[i].name << " : " << capacity << " kg " << fraction_profit << " taka" << endl;
            
                items[i].weight -= capacity;
                items[i].value-=fraction_profit;
                capacity = 0;
            }
            
            


        }
        i++;
        
    }

    return profit;
    



}


int main() {
    
    int n;
    cin>>n;

    vector<item>items(n);
    for(int i=0;i<n;i++){
        cin>>items[i].name;
        cin>>items[i].value>>items[i].weight;
    }
    int W;
    cin>>W;
    double arr[W];
    for(int i=0;i<W;i++){
     cin>>arr[i];
    }
    
    int count=0;
    for(int i=0;i<W;i++){
        double result=Fractional_Knapsack(items,n,arr[i]);
        cout<<"Thief "<<i+1<<" profit: : "<<result <<"  taka"<<endl<<endl;
        if(result!=0)
             count++;

    }
    cout<<"Total "<<count<<" thieves stole from the warehouse"<<endl;


    
    for(int i=0;i<n;i++){
        if(items[i].weight!=0){  
                cout<<"Still following items are left "<<endl;
        }

    }
    for(int i=0;i<n;i++){
        if(items[i].weight!=0){  
                cout<<items[i].name<<" :"<<items[i].weight<<"  kg   "<<items[i].value<<" taka"<<endl;
        }

    }



 
    return 0;
}