#include <iostream>
using namespace std;
 
const int maxn = 110;
int m, n; // m行，n列
int grid[maxn][maxn]; 
bool vis[maxn][maxn];
int ans[maxn * maxn];
 
int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i ++ )
        for (int j = 0; j < n; j ++ )
            cin >> grid[i][j];
 
    int Next[4][2] = {0,1,1,0,0,-1,-1,0}; 
    int x = 0, y = 0, k = 0;
    vis[0][0] = true;
 
    for (int i = 0; i < m * n; i ++ ) {
        cout << grid[x][y] << " ";
        int nx = x + Next[k % 4][0], ny = y + Next[k % 4][1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny]) {
            k ++;
            nx = x + Next[k % 4][0], ny = y + Next[k % 4][1];
        }
        vis[nx][ny] = true;
        x = nx, y = ny;
    }
    return 0;
}