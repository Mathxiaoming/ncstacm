#include <iostream>
typedef long long ll;
using namespace std;
 
int main()
{
    int n, ans = 0;
    cin >> n;
    for (ll i = 5; n / i; i *= 5)
        ans += n / i;
    cout << ans << endl;
    return 0;
}