#include <iostream>
#include <algorithm>
using namespace std;
 
const int maxn = 505;
const int INF = 0x3f3f3f3f;
int f[maxn][maxn];  // f[i][j]：j列前i行元素前缀和
int g[maxn][maxn];
int n, m;
 
int main()
{
    cin >> n >> m;
    int maxnum = -INF;
    bool flag = 0;  // 是否全为负？flag==0则全为负
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            cin >> g[i][j];
            maxnum = max(maxnum, g[i][j]);
            f[i][j] = f[i-1][j] + g[i][j];
            if (g[i][j] > 0) flag = 1;
        }
        
    if (!flag)
    {
        cout << maxnum << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = i; j <= n; j ++)
        {
            int cursum = 0;
            for (int k = 1; k <= m; k ++)
            {
                cursum += f[j][k] - f[i-1][k];
                if (cursum < 0 ) cursum = 0; 
                ans = max(ans, cursum);
            }
        }
    cout << ans << endl;
    return 0;
}