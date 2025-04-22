#include <bits/stdc++.h>
using namespace std;

struct item
{
    int id,weight,value;
};

bool compare(item a,item b){
    return (1.0*a.value/a.weight)>(1.0*b.value/b.weight);
}

double Fractional_Knapsack(vector<item>items,int n,int capacity){
   
    sort(items.begin(),items.end(),compare);
    double profit=0;
    int i=0;
    while (capacity>0)
    {
        if(capacity>items[i].weight){
            cout<<"item :"<<items[i].id<<" :"<<items[i].weight<<"  kg   "<<items[i].value<<" taka"<<endl;
            profit+=items[i].value;
            capacity-=items[i].weight;
            i++;
        }
        else{
             double fraction_weight=1.0*capacity/items[i].weight;
             double fraction_profit=items[i].value*fraction_weight;
             profit+=fraction_profit;
             cout<<"item :"<<items[i].id<<" :"<<capacity<<" kg  "<<fraction_profit<<" taka"<<endl;
             capacity=0;
        }
    }

    return profit;
    



}


int main() {
    
    int n,W;
    cin>>n;

    vector<item>items(n);
    for(int i=0;i<n;i++){
        items[i].id=i+1;
        cin>>items[i].weight>>items[i].value;
    }
    
    cin>>W;

   double result=Fractional_Knapsack(items,n,W);

    cout<<"profit : "<<result <<"  taka"<<endl;

    

    
    return 0;
}