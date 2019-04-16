#include <iostream>
#include <stack>
#include <cstring>
using ll = long long;
using namespace std;
const int maxn = 100010;
ll a[maxn];
int n;

int main()
{
    // freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    while (cin >> n && n)
    {
        ll ans = 0;
        stack<ll> stk;
        memset(a, 0, sizeof a);
        for (int i = 0; i < n; i ++) cin >> a[i];
        for (int i = 0; i <= n; i ++)
        {
            while (!stk.empty() && a[i] < a[stk.top()])
            {
                int cur = stk.top();
                stk.pop();
                if (stk.empty())
                    ans = max(ans, a[cur] * i);
                else
                    ans = max(ans, a[cur] * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        cout << ans << endl;
    }
    return 0;
}