// 图论 得分 25分(25分)
// 邻接表保存，注意颜色个数需要等于k

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int v, e, k; //顶点数、边数、颜色数
vector<int> vec[505];
int book[505]; //记录每个顶点被标记颜色
set<int> s;    //记录颜色种数

bool Judge()
{
    if (s.size() != k)
        return false; //颜色个数不等于k时，返回false
    for (int i = 1; i <= v; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            if (book[i] == book[vec[i][j]]) //表示有相邻结点颜色相同
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    cin >> v >> e >> k;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int t; //方案数
    cin >> t;
    while (t--)
    {
        s.clear(); //注意清空
        memset(book, 0, sizeof(book)); 
        for (int i = 1; i <= v; i++)
        {
            int a;
            cin >> a;
            book[i] = a;
            s.insert(a);
        }
        bool flag = Judge();
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}