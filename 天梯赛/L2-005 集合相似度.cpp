#include <iostream>
#include <unordered_set>
using namespace std;

const int maxn = 55;
int n, k;
unordered_set<int> s[maxn];

double checksim(int a, int b)
{
    double nc = 0.0, nt = 0.0;
    for (auto x : s[a])
    {
        if (s[b].count(x))
            nc++;
    }
    nt = s[a].size() + s[b].size() - nc;
    return nc / nt * 100;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int num;
            scanf("%d", &num);
            s[i].insert(num);
        }
    }

    scanf("%d", &k);
    while (k--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%.2f%c\n", checksim(a, b), '%');
    }
    return 0;
}
