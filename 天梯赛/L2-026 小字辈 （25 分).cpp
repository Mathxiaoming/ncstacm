#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
vector<int> v;          //记录它所处的辈分
vector<vector<int> > mp; //mp[i]里面存的是自己的后代
int maxn = 0;
void dfs(int x, int ans)
{
    if (mp[x].size() == 0)
    {
        maxn = max(maxn, ans - 1); //为什么要减1，因为它没有子女，而这个ans代表的是它的子女对辈分，所以减1就是它自己的
        return;
    }
    for (int i = 0; i < mp[x].size(); i++)
    {
        v[mp[x][i]] = ans;
        dfs(mp[x][i], ans + 1);
    }
}
int main()
{
    int n, temp; //temp记录祖先编号
    cin >> n;
    v.assign(n + 1, 0);
    mp.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int u;
        cin >> u;
        if (u == -1)
        {
            temp = i; //temp保存他们的祖先，dfs从temp开始
            v[i] = 1; //祖先的辈分为1
            continue;
        }
        mp[u].push_back(i); //邻接表保存辈分关系
    }
    dfs(temp, 2);
    cout << maxn << endl;
    bool flag = true;            //应题目要求，输出前后不得有多余空格，
    for (int i = 1; i <= n; i++) //所以在第二行输出时，第一个数前面不带空格，以后输出前都要先输出空格
    {                            //这样能保证最后一个数后面没有空格
        if (v[i] == maxn)
        {
            if (flag)
            {
                cout << i;
                flag = false;
            }
            else
            {
                cout << " " << i;
            }
        }
    }
    cout << endl;
    return 0;
}