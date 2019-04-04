#include <iostream>
using namespace std;

// 判断str是否为周期为p的串
bool isPer(string str, int p)
{
    for (int i = 0; i < p; i++)
        for (int j = p + i; j < str.size(); j += p)
            if (str[i] != str[j])
                return false;
    return true;
}

int main()
{
    int N;
    cin >> N;
    bool case1 = 1;
    while (N--)
    {
        if (case1) case1 = 0;
        else cout << endl;
        string str;
        cin >> str;
        int len = str.size();
        // 对周期p遍历
        for (int p = 1; p <= len; p++)
            if (!(len % p) && isPer(str, p))
            {
                cout << p << endl;
                break;
            }
    }
    return 0;
}