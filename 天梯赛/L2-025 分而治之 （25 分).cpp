/* 
解题思路：邻接表保存城市连通关系，
book数组记录首先被攻打的城市，
最后判断未被攻打的城市中与之相连的城市是否被攻打，
若存在未被攻打的，那此方案不成立 
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
vector<int> vec[10010];
int book[10010];
bool judges()
{
    for (int i = 1; i <= n; i++)
    {
        if (book[i])
            continue; //被攻打的城市不再判断
        for (int j = 0; j < vec[i].size(); j++)
        {
            if (book[vec[i][j]] == 0) //未被攻打的城市的子结点中仍然有未被攻打的城市，那就不成立
                return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> m; //n个城市，m条路
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int k; //首先攻打k个城市
    cin >> k;
    while (k--)
    {
        memset(book, 0, sizeof(book));
        int ans;
        cin >> ans;
        for (int i = 0; i < ans; i++)
        {
            int a;
            cin >> a;
            book[a] = 1; //被攻打，标记为1
        }
        bool d = judges();
        if (d)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}