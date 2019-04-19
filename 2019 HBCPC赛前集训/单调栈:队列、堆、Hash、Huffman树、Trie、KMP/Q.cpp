#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 100010;

int trie[maxn * 32][2];
int cnt[maxn];
int a[maxn];
int n, m, idx;

void insert(int num)
{
    int p = 0;
    for (int i = 30; ~i; i--)
    {
        int ch = num >> i & 1;
        int &c = trie[p][ch];
        if (!c) c = ++idx;
        p = c;
    }
}

int Find(int num)
{
    int ret = 0, p = 0;
    for (int i = 30; ~i; i --)
    {
        int ch = num >> i & 1;
        if (trie[p][!ch]) 
        {
            ret += 1 << i;
            p = trie[p][!ch];
        }
        else p = trie[p][ch];
    }
    return ret;
}

int main()
{
    // freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i ++)
        ans = max(ans, Find(a[i]));

    cout << ans << endl;

    return 0;
}