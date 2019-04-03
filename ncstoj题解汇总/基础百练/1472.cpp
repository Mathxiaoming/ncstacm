#include <iostream>
#include <queue>
 
typedef long long ll;
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll> >pq;
    pq.push(1);
    while (-- n) {
        ll top = pq.top();
        while(pq.size() && top == pq.top()) pq.pop();
        pq.push(top * 2);
        pq.push(top * 3);
        pq.push(top * 5);
    }
    cout << pq.top() << endl;
    return 0;
}