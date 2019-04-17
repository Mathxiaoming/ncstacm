#include <iostream>
#include <deque>
using namespace std;
const int maxn = 100010;
int a[maxn], ans[maxn];
int n, k;
deque<int>q;
int main()
{
    //freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        while(!q.empty() && i - q.front() >= k) q.pop_front();
        while(!q.empty() && a[i] >= a[q.back()]) q.pop_back();
        q.push_back(i);
        if(i >= k - 1) ans[i+1-k] = a[q.front()];
    }
    for (int i = 0; i + k <= n; i++)
        cout << ans[i] << " \n"[i+k==n];
    return 0;
}