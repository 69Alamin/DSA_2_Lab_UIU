#include <bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<int> pqueue;

    pqueue.push(50);
    pqueue.push(80);
    pqueue.push(10);
    pqueue.push(0);
    pqueue.push(50);

    while (!pqueue.empty())
    {
       cout<<pqueue.top()<<endl;
       pqueue.pop();
    }
    
    return 0;
}