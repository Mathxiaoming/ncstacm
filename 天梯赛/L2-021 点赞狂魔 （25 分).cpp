#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
struct list
{
    string name; //姓名
    int num;     //点赞类型
    double ave;  //点赞平均值
    bool operator<(const list b) const
    {
        if (num == b.num)
        {
            return ave < b.ave;
        }
        return num > b.num;
    }
};
int n;
list l[101];
unordered_set<int> s;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s.clear();
        int k;
        string ss;
        cin >> ss >> k;
        l[i].name = ss;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            s.insert(a);
        }
        l[i].num = s.size();
        l[i].ave = 1.0 * k / s.size();
    }
    sort(l, l + n);
    for (int i = 0; i < 3; i++)
    {
        if (i < n)
        {
            cout << l[i].name << " \n"[i == 2];
        }
        else
        {
            cout << "-"
                 << " \n"[i == 2];
        }
    }
    return 0;
}