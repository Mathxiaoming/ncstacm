// 令f(i,root)为节点i到根的异或值（路径上元素异或和），有f(a,b) = f(a,root) ^ f(b, root)
// 把所有的f(x, root)存到a[]数组中，要计算全部的a[]，可以从任意节点开始dfs，dfs中应该记录父节点，防止走回路

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100010;

int trie[maxn * 32][2];
int cnt[maxn];
int a[maxn];
int n, m, idx;
vector<pair<int, int>> g[maxn];

// 计算节点x到根节点的异或和，父节点为f，当前异或和为s
void dfs(int x, int f, int s)
{
    a[x] = s;
    for (int i = 0; i < g[x].size(); i++)
    {
        int nxt = g[x][i].first;
        int val = g[x][i].second;
        if (nxt != f)
            dfs(nxt, x, s ^ val);
    }
}

void insert(int num)
{
    int p = 0;
    for (int i = 30; ~i; i--)
    {
        int ch = num >> i & 1;
        int &c = trie[p][ch];
        if (!c)
            c = ++idx;
        p = c;
    }
}

int Find(int num)
{
    int ret = 0, p = 0;
    for (int i = 30; ~i; i--)
    {
        int ch = num >> i & 1;
        if (trie[p][!ch])
        {
            ret += 1 << i;
            p = trie[p][!ch];
        }
        else
            p = trie[p][ch];
    }
    return ret;
}

int main()
{
    // freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    dfs(0, -1, 0);

    for (int i = 0; i < n; i++)
        insert(a[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, Find(a[i]));

    cout << ans << endl;

    return 0;
}
