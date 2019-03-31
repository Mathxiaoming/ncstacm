#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
 
const int maxn = 110;
vector<pair<int, int> >E[maxn];
int n, m;
int dist[maxn];
bool vis[maxn];
 
void heap_dijkstra()
{
    priority_queue<pair<int, int> > Q;
    dist[1] = 0;
    Q.push({-dist[1], 1});
    while (!Q.empty())
    {
        int head = Q.top().second;
        Q.pop();
        if (vis[head]) continue;
        vis[head] = 1;
        for (int i = 0; i < E[head].size(); i ++ )
        {
            int v = E[head][i].first, dis = E[head][i].second;
            if (dist[v] > dis + dist[head])
            {
                dist[v] = dis + dist[head];
                Q.push({-dist[v], v});
            }
        }
    }
}
 
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b, c});
        E[b].push_back({c, b});
    }
    memset(dist, 0x3f, sizeof dist);
    heap_dijkstra();
    for (int i = 1; i <= n; i ++) cout << dist[i] << " \n"[i==n];
    return 0;
}