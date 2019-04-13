#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 20;
int f[1 << maxn][maxn];
int dist[maxn][maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for (int state = 0; state < 1 << n; state++)
        for (int i = 0; i < n; i++)
            if (state >> i & 1)
                for (int j = 0; j < n; j++)
                    if ((state - (1 << i)) >> j & 1)
                        f[state][i] = min(f[state][i], f[state - (1 << i)][j] + dist[i][j]);
    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}