#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(int a, int b)     //overload the function
    {
        return b < a;
    }
};

int main()
{

    priority_queue<int, vector<int>, compare> ala;
    ala.push(50);
    ala.push(80);
    ala.push(20);
    ala.push(90);
    ala.push(10);

    while (!ala.empty())
    {
        cout << ala.top() << endl;
        ala.pop();
    }

    return 0;
}