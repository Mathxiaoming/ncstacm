#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
priority_queue<ll> q;
int main()
{
    int n;
    cin >> n;
    q.push(-1);
    while (--n)
    {
        ll top = q.top();
        while (q.size() && top == q.top())
            q.pop();
        q.push(top * 2);
        q.push(top * 3);
        q.push(top * 5);
    }
    cout << -q.top() << endl;
    return 0;
}