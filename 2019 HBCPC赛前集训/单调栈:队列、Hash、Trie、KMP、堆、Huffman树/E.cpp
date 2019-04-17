// 维护一个单调下降的单调栈，每当有元素大于栈顶元素，则说明存在一个U形
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 20010;
int a[maxn];
stack<int> stk;
int ans = 0;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // 形成一个U形
        while (stk.size() && a[stk.top()] < a[i])
        {
            int lastTop = stk.top();
            stk.pop();
            if (stk.size())
                ans += (i - stk.top() - 1) * (min(a[i], a[stk.top()]) - a[lastTop]);
        }
        stk.push(i);
    }
    cout << ans << endl;
    return 0;
}