#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 25010;

int heaters[maxn];
int houses[maxn];
int n, m;

// 半径为r的时候，是否可以覆盖全部houses
bool check(int r)
{
    for (int i = 0, j = 0; i < n; i++)
    {
        while (abs(houses[i] - heaters[j]) > r && j < m)
            j++;
        if (j == m)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> houses[i];
    for (int i = 0; i < m; i++)
        cin >> heaters[i];
    sort(houses, houses + n);
    sort(heaters, heaters + m);
    int l = 0, r = max(houses[n - 1], heaters[m - 1]);
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}