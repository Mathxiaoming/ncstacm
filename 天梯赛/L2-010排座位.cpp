#include <vector>
#include <iostream>
using namespace std;
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

int n, m, k;        //n个人，m条关系，k次询问
int enmy[105][105]; //敌对关系
vector<int> f;      //f:father

void init(int num)
{
    for (int i = 1; i <= num; ++i)
        f[i] = i;
}

int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}

bool check(int x, int y) //检查是否是朋友
{
    return find(x) == find(y);
}

int main()
{
    cin >> n >> m >> k;
    f.resize(n + 5);
    init(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b, r;                     //a，b编号r是关系
        cin >> a >> b >> r;
        if (r == 1)                      //压缩朋友关系
            f[find(b)] = find(a);
        else
            enmy[a][b] = enmy[b][a] = 1; //敌对关系没有传递性，所以直接用矩阵保存就可以
    }
    for (int i = 0; i < k; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (check(a, b) && !enmy[a][b])
            cout << "No problem" << endl;
        else if (!check(a, b) && !enmy[a][b])
            cout << "OK" << endl;
        else if (check(a, b) && enmy[a][b])
            cout << "OK but..." << endl;
        else if (enmy[a][b])
            cout << "No way" << endl;
    }
    return 0;
}
