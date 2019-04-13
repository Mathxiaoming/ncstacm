#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100010;
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    // 从大到小枚举：求a[i]需要a[i-1]，要保证a[i-1]是原数而不是差分
    for (int i = n; i > 1; i --) a[i] -= a[i-1];
    
    ll pos = 0, neg = 0;
    for (int i = 2; i <= n; i ++ ) {
        if (a[i] > 0) pos += a[i];
        else neg -= a[i];
    }
    cout << min(pos, neg) + abs(pos - neg) << endl;
    cout << abs(pos - neg) + 1 << endl;
    
    return 0;
}
