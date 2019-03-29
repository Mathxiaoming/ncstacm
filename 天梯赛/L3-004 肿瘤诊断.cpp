#include <iostream>
#include <queue>
using namespace std;
struct point
{
    int l, r, c;
    point() {}
    point(int l, int r, int c) : l(l), r(r), c(c) {}
};
int L, R, C; //L是迷宫层数，R,C分别为行和列
int T;
int Next[6][3] = {1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1};
int g[62][130][1300];
int tot = 0;

void bfs(int l, int r, int c)
{
    int cursize = 1;
    point staPoint(l, r, c);
    queue<point> que;
    que.push(staPoint);
    g[l][r][c] = 0;
    while (!que.empty())
    {
        point head = que.front();
        que.pop();
        for (int k = 0; k < 6; k++)
        {
            int nl = head.l + Next[k][0];
            int nr = head.r + Next[k][1];
            int nc = head.c + Next[k][2];
            if (nl >= L || nr >= R || nc >= C || nl < 0 || nr < 0 || nc < 0)
                continue;
            if (g[nl][nr][nc] == 1)
            {
                g[nl][nr][nc] = 0;
                que.push(point(nl, nr, nc));
                cursize ++;
            }
        }
    }
    if (cursize >= T){
        tot += cursize;
//        cout << l << " " << r << " " << c << " "<< cursize << endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> R >> C >> L >> T;
    for (int l = 0; l < L; l++)
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                cin >> g[l][r][c];
    
    for (int l = 0; l < L; l++)
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (g[l][r][c])
                    bfs(l, r, c);
    
    cout << tot << endl;
    return 0;
}
