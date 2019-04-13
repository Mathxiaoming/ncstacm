#include <iostream>
using namespace std;
using ll = long long;

ll mul(ll a, ll b, ll p)
{
    ll ret = 0;
    for (; b; b >>= 1)
    {
        if (b & 1) ret = (ret + a) % p;
        a = a * 2 % p;
    }
    return ret;
}

int main()
{
    ll a, b, p;
    cin >> a >> b >> p;
    cout << mul(a, b, p) << endl;
    return 0;
}