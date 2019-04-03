#include <iostream>
#include <algorithm>
#include <map>
 
typedef long long ll;
using namespace std;
const int N = 50010;
const int INF = 0x3f3f3f3f;
 
int nums[N];
map<int, pair<int, int> > map1;
map<int, int> numscount;
 
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> nums[i];
 
    int degree = 0, ans = INF;
    for (int i = 1; i <= n; i ++ ) {
        int cur = nums[i];
        if (!map1[cur].first) map1[cur].first = i;
        if (i > map1[cur].second) map1[cur].second = i;
        numscount[cur] ++;
        degree = max(degree, numscount[cur]);
    }
 
    for (int i = 1; i <= n; i ++ ) {
        int cur = nums[i];
        if (degree == numscount[cur])
            ans = min(ans, map1[cur].second - map1[cur].first + 1);
    }
    cout << ans << endl;
    return 0;
}