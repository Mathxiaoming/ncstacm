#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct State
{
	int keys, x, y, step; // keys代表当前状态(点x,y)拥有的钥匙的个数
	State(int keys, int x, int y, int step) : keys(keys), x(x), y(y), step(step) {}
};
bool vis[35][35][65];
int totState = 0;
int Next[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int n, m;
int sx = -1, sy = -1;
char grid[35][35];
int bfs()
{
	queue<State> Q;
	Q.push(State(0, sx, sy, 0));
	vis[sx][sy][0] = 1;
	while (!Q.empty())
	{
		State head = Q.front();
		Q.pop();
		for (int k = 0; k < 4; k++)
		{
			int x = head.x, y = head.y, keys = head.keys, step = head.step;
			int nx = x + Next[k][0];
			int ny = y + Next[k][1];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '#')
			{
				char c = grid[nx][ny];

				if (islower(grid[nx][ny]))
					keys |= 1 << (grid[nx][ny] - 'a');
				// 遇到门
				else if (isupper(grid[nx][ny]) && !(keys >> (grid[nx][ny] - 'A') & 1))
					continue;
				if (!vis[nx][ny][keys])
				{
					if (keys == totState)
						return step + 1;
					vis[nx][ny][keys] = true;
					Q.push(State(keys, nx, ny, step + 1));
				}
			}
		}
	}
	return -1;
}

int main()
{
	// freopen("/Users/zhbink/Documents/C++/C++/in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == '@')
				sx = i, sy = j;
			if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
				totState = max(totState, totState |= 1 << (grid[i][j] - 'a'));
		}
	}
	cout << bfs() << endl;
}
