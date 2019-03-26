// 并查集 得分 20分(25分)

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n;
int fa[10010];          //fa[i]表示i的祖先是fa[i]
int ranks[10010] = {0}; 
int maxn = 0;           //记录最大编号
int ans = 0;            //记录朋友圈数量
int findroot(int x)     //路径压缩
{
    if (x == fa[x])
        return x;
    return fa[x] = findroot(fa[x]);
}
void merge(int x, int y) //合并
{
    int fx = findroot(x);
    int fy = findroot(y);
    if (fx == fy)
        return;
    if (ranks[fx] < ranks[fy])
    {
        fa[fx] = fy;
    }
    else
    {
        fa[fy] = fx;
        if (ranks[fx] == ranks[fy])
            ranks[fx]++;
    }
}
void init() //初始化
{
    for (int i = 1; i < 10010; i++)
    {
        fa[i] = i;
    }
}
int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a;
        cin >> a; //记录每个朋友圈的第一人，方便与其他人合并
        maxn = max(maxn, a);
        for (int i = 0; i < n - 1; i++)
        {
            int b;
            cin >> b;
            maxn = max(maxn, b);
            merge(a, b); //合并a和b
        }
    }
    for (int i = 1; i <= maxn; i++)
    {
        if (i == fa[i])
            ans++;
    }
    cout << maxn << " " << ans << endl;
    int num; //查询次数
    cin >> num;
    while (num--)
    {
        int x, y;
        cin >> x >> y;
        if (fa[x] == fa[y])
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}