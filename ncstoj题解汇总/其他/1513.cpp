#include <iostream>
#include <sstream>
#include <cmath>
typedef long long ll;
using namespace std;

int l, k;
string num;

bool isprime(ll number)
{
    if (number <= 1) return false;
    for (ll i = 2; i < sqrt(number); i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
ll str2ll(string str)
{
    ll ret;
    stringstream ss;
    ss << str;
    ss >> ret;
    return ret;
}
int main()
{
    cin >> l >> k >> num;
    for (int i = 0; i + k <= num.size(); i++)
    {
        string str = num.substr(i, k);
        if (isprime(str2ll(str)))
        {
            cout << str << endl;
            return 0;
        }
    }
    cout << "404" << endl;
    return 0;
}