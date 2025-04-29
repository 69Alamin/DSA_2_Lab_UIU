#include <bits/stdc++.h>
using namespace std;

struct Question
{
    int id,marks,time;
};

struct result
{
    int id;
    double percentage,marks;
};

bool compare(Question a,Question b){
    return (1.0*a.marks/a.time)>(1.0*b.marks/b.time);
}

vector<result>Maximize_Marks(vector<Question>questions,int N,int time){
    sort(questions.begin(),questions.end(),compare);

    vector<result>rt;
    int i=0;
    while (time>0)
    {
        if(questions[i].time<=time){
            rt.push_back({questions[i].id,100,questions[i].marks*1.0});
            time-=questions[i].time;
        }
        else{
             
            double marks=((double)questions[i].marks/questions[i].time)*time;
            double percent=(marks*100)/questions[i].marks;
            rt.push_back({questions[i].id,percent,marks});
            time=0;
            

        }
        i++;
    }

    return rt;
    

}




int main() {
    int Marks,Time,N;
    cin>>Marks>>Time>>N;
    vector<Question>queston;
    Question a;
    for(int i=0;i<N;i++){
        a.id=i+1;
        cin>>a.marks>>a.time;
        queston.push_back(a);
    }
   
    vector<result>rs=Maximize_Marks(queston,N,Time);
     
    double max=0;
    for(int i=0;i<rs.size();i++){
            max+=rs[i].marks;
    }
    cout<<"Maximum "<<max<< " marks answering alone"<<endl;
    for(int i=0;i<rs.size();i++){
        cout<<"ques "<<rs[i].id<<" "<<rs[i].percentage<< "% done ------"<<rs[i].marks<<" marks"<<endl;
    }



    vector<result>rs2=Maximize_Marks(queston,N,Time*2);
    double max2=0;
    for(int i=0;i<rs2.size();i++){
            max2+=rs2[i].marks;
    }
    cout<<"Maximum  "<< max2<<" marks answering with a friend"<<endl;
    
    
    return 0;
}