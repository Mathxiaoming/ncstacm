#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int n, k, num;
    cin >> n;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        if (k == 1)
        {
            cin >> num;
            if (m[num] == 1) //如果已经在一个朋友圈里了
                continue;
            else
                m[num] = 0;
        }
        else
        {
            for (int j = 0; j < k; ++j)
            {
                cin >> num;
                m[num] = 1;
            }
        }
    }

    int ask, cnt = 0;
    cin >> ask;
    for (int i = 0; i < ask; ++i)
    {
        cin >> num;
        if (!m.count(num) || m[num] == 0)
        {
            m[num] = -1; //标记已经访问过，不会再重复访问
            if (cnt == 0)
                printf("%05d", num);
            else
                printf(" %05d", num);
            ++cnt;
        }
    }
    if (cnt == 0)
        cout << "No one is handsome" << endl;
    return 0;
}