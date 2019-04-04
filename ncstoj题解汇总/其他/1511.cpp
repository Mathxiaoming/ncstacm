#include <iostream>
using namespace std;

const int maxn = 100010;
int prime[maxn]; // 存放所有素数
int tot;         // 素数的个数
bool p[maxn];    // p[i]=true代表p[i]是素数

// maxn以内的素数放进prime[]中
void findPrime(int n)
{
    for (int i = 1; i <= n; i++)
        p[i] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (p[i])
        {
            prime[tot++] = i;
            for (int j = i; j <= n / i; j++)
                p[i * j] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    findPrime(n);
    int ans = 0;
    for (int i = 1; i < tot; i++)
    {
        if (prime[i] - prime[i - 1] == 2)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
