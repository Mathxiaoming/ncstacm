#include <iostream>
#include <algorithm>
using namespace std;
 
const int N = 50010;
int prices[N];
 
int main()
{
    int n, ans = 0, minstock = N;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> prices[i];
    for (int i = 0; i < n; i++)
    {
        if (prices[i] < minstock) minstock = prices[i];
        else ans = max(ans, prices[i] - minstock);
    }
    cout << ans << endl;
}