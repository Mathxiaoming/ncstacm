#include <stdio.h>
#include <stack>
using namespace std;
const int N = 101000;
int n, m, i, j, k, a[N], ans[N];
stack<pair<int, int>> stk;
int main()
{
    // freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        while (stk.size() && a[i] > stk.top().first)
        {
            ans[stk.top().second] = i;
            stk.pop();
        }
        stk.push({a[i], i});
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}