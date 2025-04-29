#include <bits/stdc++.h>
using namespace std;

int changes[] = {25, 10, 1};
int counts[3] = {0};

int Changes_coin(int n)
{

    int total = 0;
    int i = 0;
    while (n != 0)
    {
        if (n >= changes[i])
        {  int this_coin_need=n/changes[i];
            n -= changes[i]*this_coin_need;
            counts[i]=this_coin_need;
            total+=this_coin_need;
        }
            i++;
    }

    return total;
}

int main()
{

    int N;
    cin >> N;

    int n = Changes_coin(N);
    for (int i = 0; i < 3; i++)
    {
        cout << changes[i] << "  cents-----" << counts[i] << endl;
    }

    cout << "Total " << n << "  coins";

    return 0;
}