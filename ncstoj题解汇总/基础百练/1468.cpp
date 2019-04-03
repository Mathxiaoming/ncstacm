#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[100050];
int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i ++ ) cin >> a[i];
    int ans = -INF, cursum = 0;
    for (int i = 0; i < N; i ++) {
        cursum += a[i];
        ans = max(ans, cursum);
        if (cursum < 0) cursum = 0;
    }
    cout << ans << endl;
    return 0;
}