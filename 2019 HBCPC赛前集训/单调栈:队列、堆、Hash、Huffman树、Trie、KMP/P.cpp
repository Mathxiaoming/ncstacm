#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 1000010;

int trie[maxn][26];
int cnt[maxn];
char str[maxn];
int n, m, idx;

void insert()
{
    int p = 0;
    for (int i = 0; str[i]; i ++)
    {
        int &c = trie[p][str[i] - 'a'];
        if (!c) c = ++idx;
        p = c;
    }
    cnt[p] ++;
}

int query()
{
    int p = 0, sum = 0;
    for (int i = 0; str[i]; i ++)
    {
        int &c = trie[p][str[i] - 'a'];
        if (!c) break;
        p = c;
        sum += cnt[p];
    }
    return sum;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
    {
        scanf("%s", str);
        insert();
    }

    for (int i = 0; i < m; i ++)
    {
        scanf("%s", str);
        printf("%d\n", query());
    }
    return 0;
}