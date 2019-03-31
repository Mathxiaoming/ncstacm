#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
 
int n, a[maxn], q[maxn], tot;
 
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
 
    q[++ tot] = a[1];
    for (int i = 2; i <= n; i++ )
    {
        if (a[i] > q[tot]) q[++ tot] = a[i];
        else
        {
            int tmp = lower_bound(q + 1, q + tot + 1, a[i]) - q;
            q[tmp] = a[i];
        }
    }
    cout << tot << endl;
    return 0;
}