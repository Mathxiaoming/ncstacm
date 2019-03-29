#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int map1[maxn];
int f[maxn];
int ans[maxn];
void init(int n)
{
    for (int i = 1; i <= n; i++) f[i] = i;
}

int find(int x)
{
    return f[x] = f[x] == x ? x : find(f[x]);
}

void merge(int a, int b)
{
    int fa = find(a), fb = find(b);
    // if (fa > fb) swap(fa, fb);
    if (fa != fb)
        f[fb] = fa;
}

bool cmp(int a, int b) {return a > b;}

int main()
{
//    freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; i ++)
    {
        int ncase;
        scanf("%d:", &ncase);
        while (ncase --)
        {
            int h;
            cin >> h;
            if (map1[h] == 0) map1[h] = i;
            merge(find(map1[h]), i);
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        ans[find(i)]++;
    for(int i = 1; i <= n; i++) {
        if(ans[i] != 0)
            cnt++;
    }

    cout << cnt << endl;
    sort(ans + 1, ans + 1 + maxn, cmp); 
    for (int i = 1; i <= cnt; i ++)
        cout << ans[i] << " \n"[i==cnt];
    return 0;
}
