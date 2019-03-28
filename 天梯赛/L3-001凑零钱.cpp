/*
01背包问题中 dp[v]表示物品恰好装入容量为v的背包中能获得的最大价值（恰好是最大的意思）

经过以下2点转换为01背包问题：
1. 本题中 每个硬币的价值和体积相等。
2. 本题中 “当前目标为取v元的硬币” -> “装入容量为v的背包”

dp[v]表示硬币恰好装入容量为v的背包中能获得的最大价值， 即：目标为v元时可以取的最大价值

因为要输出从小到大的排列，而01背包的动态规划算法是从后向前遍历，所以可以先把硬币面额从大到小排列
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int dp[maxn], w[maxn];  
bool vis[maxn][maxn];  // vis[i][v] 记录 前i种硬币恰好装入容量为v的背包中所能获得的最大价值
int n, m;  // 硬币数、目标和
vector<int> ans;

int cmp(int a, int b) { return a > b; }
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    sort(w + 1, w + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        for (int v = m; v >= w[i]; v--)
        {
            // 取第i种硬币 可以更新 目标为v元时可以取的最大价值
            if (dp[v] <= dp[v - w[i]] + w[i])
            {
                vis[i][v] = true;
                dp[v] = dp[v - w[i]] + w[i];
            }
        }
    }

    // 如果目标为m元时可以取的最大价值 不能达到m元
    if (dp[m] < m)
        cout << "No Solution" << endl;
    else
    {
        int i = n;
        while (m > 0)
        {
            if (vis[i][m] == true)
            {
                ans.push_back(w[i]);
                m -= w[i];
            }
            i--;
        }
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i+1==ans.size()];
    }
    return 0;
}