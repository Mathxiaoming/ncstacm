// 双指针，分对称子串长度为奇偶两种情况。
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int n;

struct Person
{
    int id;
    int money;
    int tot;
    bool operator<(const Person &p) const
    {
        return money > p.money || (money == p.money && tot > p.tot);
    }
} person[maxn];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        person[i].id = i;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int p, m; // 收到红包的人p, 收到的红包金额m
            cin >> p >> m;
            person[p].money += m;
            person[p].tot++;
            person[i].money -= m;
        }
    }
    sort(person + 1, person + n + 1);
    for (int i = 1; i <= n; i ++)
        printf("%d %.2f\n", person[i].id, person[i].money/100.0);
    return 0;
}