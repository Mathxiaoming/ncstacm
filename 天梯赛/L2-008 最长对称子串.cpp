// 双指针，分对称子串长度为奇偶两种情况。
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int n = str.size();

    int maxlen = 0;
    for (int pos = 0; pos < n; pos ++)
    {
        // 对称子串长度为偶数的情况
        int i = pos, j = pos + 1;
        while (i >= 0 && j <= n && str[i] == str[j])
        {
            i --, j ++;
        }
        int curlen = j - i - 1;
        maxlen = max(maxlen, curlen);

        // 对称子串长度为奇数的情况
        i = pos - 1, j = pos + 1;
        while (i >= 0 && j <= n && str[i] == str[j])
        {
            i --, j ++;
        }
        curlen = j - i - 1;
        maxlen = max(maxlen, curlen);
    }
    cout << maxlen << endl;
    return 0;
}