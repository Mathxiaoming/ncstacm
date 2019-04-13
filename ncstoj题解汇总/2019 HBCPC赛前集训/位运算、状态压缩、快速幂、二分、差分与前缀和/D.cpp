#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
using namespace std;

char grid[6][6];
int Next[5][2] = {0, 0, 0, 1, 0, -1, 1, 0, -1, 0};

void turn(int x, int y)
{
    for (int k = 0; k < 5; k++)
    {
        int nx = x + Next[k][0];
        int ny = y + Next[k][1];
        if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
            grid[nx][ny] ^= 1;
    }
}

int main()
{
    // freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 5; i++)
            cin >> grid[i];

        int ans = INT_MAX;
        for (int state = 0; state < 1 << 5; state++)
        {
            int step = 0;
            char backup[6][6];
            memcpy(backup, grid, sizeof backup);
            for (int j = 0; j < 5; j++)
                if (state >> j & 1)
                {
                    turn(0, j);
                    step ++;
                }
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 0; j < 5; j++)
                    if (grid[i - 1][j] == '0')
                    {
                        turn(i, j);
                        step ++;
                    }
            }
            int j = 0;
            for (; j < 5; j++)
            {
                if (grid[4][j] == '0')
                    break;
            }
            if (j == 5)
                ans = min(ans, step);
            memcpy(grid, backup, sizeof grid);
        }
        if (ans > 6)
            ans = -1;
        cout << ans << endl;
    }

    return 0;
}