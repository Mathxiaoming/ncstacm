#include <iostream>
#include <queue>
#include <stdio.h>
using ll = long long;
using namespace std;

priority_queue<ll> pq;
int n;

int main()
{
    ll num, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        scanf("%lld", &num);
        pq.push(-num);
    }

    while (pq.size() > 1)
    {
        num = 0;
        for (int i = 0; i <= 1; i++)
        {
            num += pq.top();
            pq.pop();
        }
        sum += num;
        pq.push(num);
    }
    cout << -sum << endl;
    return 0;
}