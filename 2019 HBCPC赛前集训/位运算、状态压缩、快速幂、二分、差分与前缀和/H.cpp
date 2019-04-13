#include <iostream>
using namespace std;
 
const int maxn = 5010;
 
int g[maxn][maxn];
 
int main() {
    int N, R; // N是点的数量，R是边长
    cin >> N >> R;
    int n = R, m = R;
    for (int i = 0; i < N; i ++ ) {
        int x, y, w;
        cin >> x >> y >> w;
        g[++x][++y] += w;
        n = max(n, x), m = max(m, y);
    }
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            g[i][j] += g[i-1][j] + g[i][j-1] - g[i-1][j-1];
            
    int res = 0;
    for (int i = R; i <= n; i ++ )
        for (int j = R; j <= m; j ++ )
            res = max(res, g[i][j] - g[i-R][j] - g[i][j-R] + g[i-R][j-R]);
            
    cout << res << endl;
    return 0;
}