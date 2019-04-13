# include <iostream>
using namespace std;
const int maxn = 10000010;
int n, m, prime[maxn], tot, s;
int v[maxn];
 
void findPrime()
{
	for (int i = 2; i <= n; i ++)
	{
		if (v[i]==0) {v[i] = i; prime[tot++] = i;}
		for (int j = 0; j < tot; j ++)
		{
			if (prime[j] > v[i] || prime[j] > n/i) break;
			v[i*prime[j]] = prime[j];
		}
	}
}
 
int main() {
    cin >> n >> m;
    findPrime();
    while(m--) {
        cin >> s;
        int l = 0, r = tot-1, mid;
        while(l < r) {
            mid = (l + r) >> 1;
            if (s <= prime[mid]) r = mid;
            else l = mid + 1;
        }
        if(s == prime[l]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}