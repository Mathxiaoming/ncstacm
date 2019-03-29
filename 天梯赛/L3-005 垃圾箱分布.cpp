// 把每个垃圾桶拎出来求最短路
// 垃圾桶的序号设立为 N+1 ~ N+M

// 最后一个点运行时错误是为什么？ 数组越界？

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1500;
const int INF = 0x3f3f3f3f;
int dist[maxn];
int vis[maxn];
int N, M, K, Dmax; // 居民数，垃圾箱数, 路径数，垃圾箱最大距离
vector<pair<int, int>> E[maxn];
struct Ans
{
    int mindis;
    double avedis;
    string id;
    Ans(int a, double b, string c)
    {
        mindis = a;
        avedis = b;
        id = c;
    }
    bool operator<(const Ans &a) const
    {
        return (mindis > a.mindis) || (mindis == a.mindis && avedis < a.avedis) || (mindis == a.mindis && avedis == a.avedis && id < a.id);
    }
};
vector<Ans> ans;

int getid(char g[])
{
    int x;
    if (g[0] == 'G')
    {
        if (g[2] != '\0')
            x = (g[1] - '0') * 10 + g[2] - '0';
        else
            x = g[1] - '0';
        x += N;
    }
    else
    {
        if (g[1] != '\0')
        {
            x = (g[0] - '0') * 10 + g[1] - '0';
        }
        else
            x = g[0] - '0';
    }
    return x;
}

void dijkstra(int sta) // sta：起点（当前的垃圾箱）
{
    priority_queue<pair<int, int>> Q;
    dist[sta] = 0;
    Q.push({-dist[sta], sta});
    while (!Q.empty())
    {
        int head = Q.top().second;
        Q.pop();
        if (vis[head])
            continue;
        vis[head] = 1;
        for (int i = 0; i < E[head].size(); i++)
        {
            int v = E[head][i].first;
            int d = E[head][i].second;
            if (dist[v] > d + dist[head])
            {
                dist[v] = d + dist[head];
                Q.push({-dist[v], v});
            }
        }
    }
}

int main()
{
    // freopen("/Users/zhbink/Documents/C++/C++/in.txt", "r", stdin);
    scanf("%d%d%d%d", &N, &M, &K, &Dmax);
    for (int i = 0; i < K; i++)
    {
        int a, b, c;
        char g1[3], g2[3];
        scanf("%s%s%d", g1, g2, &c);
        a = getid(g1);
        b = getid(g2);
        E[a].push_back({b, c});
        E[b].push_back({a, c});
    }
    for (int i = N + 1; i <= N + M; i++)
    {
        for (int j = 1; j <= N + M; j++)
            dist[j] = INF;
        memset(vis, 0, sizeof(vis));
        dijkstra(i);
        int mindis = INF;
        int maxdis = -1;
        double dissum = 0;
        for (int j = 1; j <= N; j++)
        {
            if (dist[j] < mindis)
                mindis = dist[j];
            if (dist[j] > maxdis)
                maxdis = dist[j];
            dissum += (double)dist[j];
        }
        if (maxdis > Dmax)
            continue;
        string id = "G";
        id += to_string(i - N);
        ans.push_back(Ans(mindis, dissum / N, id));
    }
    if (ans.size())
    {
        sort(ans.begin(), ans.end());
        printf("%s\n%.1f %.1f\n", ans[0].id.c_str(), (double)ans[0].mindis, (int)(ans[0].avedis * 10 + 0.5) / 10.0);
    }
    else
        printf("No Solution\n");
    return 0;
}
