#include <iostream>
#include <algorithm>
using namespace std;
 
const int maxn = 5010;
int a[maxn];
 
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    int ans = 0;
    for (int i = 0, j = n - 1; i <= j;) {
        ans = max(ans, (j - i) * min(a[i], a[j]));
        if (a[i] < a[j]) i ++;
        else j --;
    }
    cout << ans << endl;
    return 0;
}