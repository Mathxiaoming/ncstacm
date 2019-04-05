#include <iostream>
using namespace std;
using ll = long long;

// a*b % p
ll mul(ll a, ll b, ll p)
{
    ll ans = 0;
    while (b)
    {
        if (b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return ans;
}

// a^b % p
ll power(ll a, ll b, ll p)
{
    ll ans = 1 % p;
    while (b)
    {
        if (b & 1) ans = mul(ans, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return ans;
}

void makeans(int ans)
{
    string ret = to_string(ans);
    while(ret.size() != 4)
    {
        ret = '0' + ret;
    }
    cout << ret << endl;
}
int main()
{
    ll n, m, p;
    cin >> n >> m;
    int ans = power(n, m, 10000);
    if (ans < 1000) makeans(ans);
    else cout << ans << endl;
    return 0;
}
