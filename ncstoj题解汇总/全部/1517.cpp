#include<iostream>
using namespace std;

const int maxn =1000010;
int t;

int n, m, prime[maxn], tot, s;
bool v[maxn];
 
void findPrime()
{
    for (int i = 2; i <= n; i++)
    {
        if (v[i]) continue;
        prime[tot++] = i;
        for (int j = i; j <= n/i; j ++) v[i*j] = 1;
    }
}

void fc(int n)
{
    int ans = 1, i = 1;
    while(n!=1) 
    {
        int cnt = 1;
        while(n%prime[i] == 0)
        {
            cnt++;
            n/=prime[i];
        }
        i++;
        ans *= cnt;
    }
    cout << ans << endl;
}

int main()
{
    cin >> t;
    findPrime();
    while (t --)
    {
        cin >> n;
        fc(n);
    }
    return 0;
}