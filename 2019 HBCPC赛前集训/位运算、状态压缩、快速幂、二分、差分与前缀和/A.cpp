#include <iostream>
using namespace std;
using ll = long long;

// a ^ b % p
int power(int a, int b, int p)
{
    int ret = 1 % p;  // %p是防止b=0。b=0时应该输出0
    for (; b; b >>= 1)
    {
        if (b & 1)
            ret = (ll)ret * a % p;
        a = (ll)a * a % p;
    }
    return ret;
}

int main()
{
    int a, b, p;
    cin >> a >> b >> p;
    cout << power(a, b, p) << endl;
    return 0;
}