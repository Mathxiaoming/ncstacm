#include <iostream>
using namespace std;
 
const int N = 105;
int grid[N][N];
 
int main()
{
    int n, m;
    cin >> n >> m;
    int tot = 0, neighbors = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ ) {
            cin >> grid[i][j];
            tot += grid[i][j];
            if (i && grid[i][j] && grid[i - 1][j]) neighbors ++ ;
            if (j && grid[i][j] && grid[i][j - 1]) neighbors ++ ;
        }
    cout << 4 * tot - neighbors * 2 << endl;
    return 0;
}