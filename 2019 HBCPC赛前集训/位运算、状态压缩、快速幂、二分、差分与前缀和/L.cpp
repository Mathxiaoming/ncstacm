#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int n, f;
int cows[maxn];
double sum[maxn];

bool check(double avg)
{
    for (int i = 1; i <= n; i ++) sum[i] = sum[i-1] + cows[i] - avg;
    double minl = 0;
    for (int r = f, l = 0; r <= n; r ++, l ++ )
    {
        minl = min(minl, sum[l]);
        if (sum[r] - minl >= 0) return true;
    }
    // for (int r = f; r <= n; r ++)
    // {
    //     for (int l = 0; l + f <= r; l ++)
    //     {
    //         if (sum[r] - sum[l] >= 0) return true;
    //     }
    // } 
    return false;
}

int main()
{
    cin >> n >> f;
    for (int i = 1; i <= n; i ++) cin >> cows[i];
    double l = 0, r = 2000;
    while (r - l > 1e-5)
    {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << int(r * 1000) << endl;
    return 0;
}