#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;  // 第一维是单词出现的次数；第二维是当前深度

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll a;
		scanf("%lld", &a);
		q.push({a, 0});
	}
    
    // 构造一颗满K叉树
	while ((n - 1) % (k - 1)) {
		++n;
		q.push({0, 0});
	}

	ll ans = 0;
	while (q.size() > 1) {
		ll num = 0, w = 0;
		for (int i = 1; i <= k; i++) {
			num += q.top().first;
			w = max(w, q.top().second);  // 当前节点深度决定于最大的w
			q.pop();
		}
		ans += num;
		q.push({num, w + 1});
	}
	cout << ans << endl << q.top().second << endl;
	return 0;
}


#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
priority_queue<pair<ll, ll> > q;  

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll a;
		scanf("%lld", &a);
		q.push({-a, 0});
	}
    
    
	while ((n - 1) % (k - 1)) {
		++n;
		q.push({0, 0});
	}

	ll ans = 0;
	while (q.size() > 1) {
		ll num = 0, w = 0;
		for (int i = 1; i <= k; i++) {
			num += q.top().first;
			w = min(w, q.top().second);
			q.pop();
		}
		ans += -num;
		q.push({num, w - 1});
	}
	cout << ans << endl << -q.top().second << endl;
	return 0;
}
