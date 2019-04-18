#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

using ull = unsigned long long;

const int maxn = 1000010;
char str[maxn];
ull s[maxn], p[maxn];

ull H (int l, int r)
{
    return s[r] - s[l-1] * p[r-l+1];
}

bool isEqual(int l1, int r1, int l2, int r2)
{
    return H(l1, r1) == H(l2, r2);
}

int main()
{
    scanf("%s", str + 1);
    p[0] = 1;
    int n = strlen(str + 1);
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i-1] * 131 + (str[i] - 'a' + 1);
        p[i] = p[i-1] * 131;
    }
    int t;
    scanf("%d", &t);
    while (t --)
    {
        int l1, r1, l2, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if (isEqual(l1, r1, l2, r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}