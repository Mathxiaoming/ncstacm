#include <iostream>
#include <deque>
using namespace std;
int n, m;
const int INF = 0x3f3f3f3f;
const int maxn = 3000010;
int a[maxn], s[maxn];
deque<int> q;
 
int main()
{
    // freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    
    int ans = -INF;
    for (int i = 1; i <= n; i ++)
    {
        while (q.size() && q.front() + m < i) q.pop_front();
        ans = max(ans, s[i] - s[q.front()]);
        while (q.size() && s[q.back()] >= s[i]) q.pop_back();
        q.push_back(i);
    }
    cout << ans << endl;
    return 0;
}