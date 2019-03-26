#include <cstring>
#include <iostream>
using namespace std;
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// 思路是每次攻占一个城市后重新建立并查集，孤立的条件是一个点的根节点是自己
const int maxn = 505;
int f[maxn];                     //父亲节点
bool lost[maxn];                 //记录是否被占领
pair<int, int> point[maxn * 10]; //记录道路信息

void init(int n)
{
    for (int i = 0; i < n; ++i)
        f[i] = i;
}

int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(int x, int y)
{
    f[find(y)] = find(x);
}

int main()
{
    int n, m;
    cin >> n >> m;
    init(n);
    memset(lost, false, sizeof(lost));
    for (int i = 0; i < m; ++i)
    {
        cin >> point[i].first >> point[i].second;
        merge(point[i].first, point[i].second); //合并结点
    }

    int pre = 0; //初始状态下的孤立点和主城市点(根节点)，样例数据中的2和0
    for (int i = 0; i < n; ++i)
        if (f[i] == i)
            ++pre;

    int k, city; //询问数，被攻占的城市号
    cin >> k;
    for (int t = 0; t < k; ++t)
    {
        cin >> city;
        lost[city] = true;
        init(n);                    //有一座城市被攻占，重新建立并查集
        for (int i = 0; i < m; ++i) //两个城市都没被占领的情况下，压缩
            if (!lost[point[i].first] && !lost[point[i].second])
                merge(point[i].first, point[i].second);

        int now = 0;      //占领一座城市后的孤立点或主城市结点(根节点)的个数
        for (int i = 0; i < n; ++i)
            if (!lost[i] && f[i] == i) ++now;    //同样要求不能被占领
        
        //不会改变连通性的两种情况：1:孤立点被占领;2:叶节点城市被占领。
        //比如第一次2号城市被占领，1号城市被占领
        if (now + 1 == pre || now == pre)                   
            cout << "City " << city << " is lost." << endl; 
        else
            cout << "Red Alert: City " << city << " is lost!" << endl;
        pre = now; //更新数量
    }

    if (k == n)
        cout << "Game Over." << endl;
    return 0;
}
