#include <iostream>
using namespace std;

int vis[127];
string str1, str2, ans;

int main()
{
    getline(cin, str1);
    getline(cin, str2);
    ans = str1 + str2;
    for (char &c : ans)
    {
        if (!vis[c])
        {
            vis[c] = 1;
            cout << c;
        }
    }
    return 0;
}

