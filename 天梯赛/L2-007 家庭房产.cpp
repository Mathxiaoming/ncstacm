#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int n;

struct Person
{
    int id, pnum;       //编号, 人数
    double size, house; // 面积,房产套数
    bool operator<(const Person &p) const
    {
        return (size / pnum > p.size / p.pnum) || (size / pnum == p.size / p.pnum && id < p.id);
    }
} person[maxn];

int f[maxn];
bool flag[maxn]; // 记录0～maxn中出现的编号
vector<Person> ans;

void init()
{
    for (int i = 1; i <= maxn; i++)
        f[i] = i;
}

int find(int v)
{
    return f[v] = f[v] == v ? v : find(f[v]);
}

void merge(int a, int b)
{
    int fa = find(a), fb = find(b);
    // 小号做父亲
    if (fa > fb)
        swap(fa, fb);
    if (fa != fb)
        f[fb] = fa;
}

int main()
{
    cin >> n;
    init();

    for (int i = 0; i < n; i++)
    {
        int id, faid, moid;  // 当前编号，父亲编号，母亲编号
        cin >> id >> faid >> moid;
        flag[id] = 1;
        if (faid != -1)
        {
            merge(id, faid);
            flag[faid] = 1;
        }
        if (moid != -1)
        {
            merge(id, moid);
            flag[moid] = 1;
        }
        int k;
        cin >> k;
        while (k--)
        {
            int chid; //孩子编号
            cin >> chid;
            flag[chid] = 1;
            merge(id, chid);
        }
        cin >> person[id].house >> person[id].size;
    }

    for (int i = 0; i < maxn; i++)
    {
        if (!flag[i])
            continue;
        int fa = find(i);
        if (fa == i)
        {
            person[i].pnum++;
            person[i].id = i;
        }
        else
        {
            person[fa].pnum++;
            person[fa].house += person[i].house;
            person[fa].size += person[i].size;
        }
    }

    for (int i = 0; i < maxn; i++)
    {
        if (!flag[i])
            continue;
        int fa = find(i);
        if (fa == i && flag[i])
            ans.push_back(person[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].pnum, ans[i].house / ans[i].pnum, ans[i].size / ans[i].pnum);
    return 0;
}
