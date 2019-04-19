// 回文串长度有偶数个的，如abba，也有奇数个的，如abcba。常规的判断需要分这两种情况。
// 回文串预处理：把回文串的头、尾、每两个字中间都加一个字符，如'#'。所有的回文串都可以按照长度为奇数的情况来判断。

// 在遍历回文中点，寻找最大半径时
// 法1 根据哈希求最大半径，时间复杂度 O(n)
// 法2 二分求最大半径，时间复杂度 O(nlogn)

// 根据哈希求最大半径
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

using ull = unsigned long long;

const int maxn = 2000010;
const int P = 13331;
char str[maxn], str2[maxn];
ull hl[maxn], hr[maxn], p[maxn];

// #a#b#c#b#a# 
// pos = 6, r = 5
// 找    #b#a#
ull HL(int pos, int r)
{
    return hl[pos + r] - hl[pos] * p[r];
}

// a#b#c#b#a 
// pos = 6, r = 5
// 找#a#b#
ull HR(int pos, int r)
{
    return hr[pos - r] - hr[pos] * p[r];
}

int main()
{
    // freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    int t = 0;
    while (scanf("%s", str+1), strcmp(str + 1, "END"))
    {
        cout << "Case " << ++t << ": ";
        int n = strlen(str + 1);
        // 把字符串长度全部变成奇数，回文性不变
        int cur = 0;
        str2[++cur] = '#';
        for (int i = 1; i <= n; i ++)
        {
            str2[++cur] = str[i];
            str2[++cur] = '#';
        }
        n = cur;

        // 构造字符串哈希
        p[0] = 1; hr[n+1] = 0;
        for (int i = 1; i <= n; i ++){
            hl[i] = hl[i-1] * P + (str2[i] - 'a' + 1);
            p[i] = p[i-1] * P;
        }
        for (int j = n; j >= 1; j --)
            hr[j] = hr[j+1] * P + (str2[j] - 'a' + 1);

        // 遍历回文中点，根据哈希寻找最大半径r，O(n)
        int r = 0;
        for (int i = 1; i <= n; i ++)
        {
            if (i - r < 0 || i + r > n) break;
            if (HL(i, r) != HR(i, r)) continue;
            // #a#b#c#b#a#
            // str2[i-r ... i+r]相同
            // i = 6, r = 5
            while (str2[i-r-1] == str2[i+r+1] && i-r-1>=1 && i+r+1 <= n) r++;
        }
        cout << r << endl;
    }
    return 0;
}


// 二分半径
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

using ull = unsigned long long;

const int maxn = 2000010;
const int P = 13331;
char str[maxn], str2[maxn];
ull hl[maxn], hr[maxn], p[maxn];

// #a#b#c#b#a# 
// pos = 6, r = 5
// 找    #b#a#
ull HL(int pos, int r)
{
    return hl[pos + r] - hl[pos] * p[r];
}

// a#b#c#b#a 
// pos = 6, r = 5
// 找#a#b#
ull HR(int pos, int r)
{
    return hr[pos - r] - hr[pos] * p[r];
}

int main()
{
    // freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    int t = 0;
    while (scanf("%s", str+1), strcmp(str + 1, "END"))
    {
        cout << "Case " << ++t << ": ";
        int n = strlen(str + 1);
        // 把字符串长度全部变成奇数，回文性不变
        int cur = 0;
        str2[++cur] = '#';
        for (int i = 1; i <= n; i ++)
        {
            str2[++cur] = str[i];
            str2[++cur] = '#';
        }
        n = cur;

        // 构造字符串哈希
        p[0] = 1; hr[n+1] = 0;
        for (int i = 1; i <= n; i ++){
            hl[i] = hl[i-1] * P + (str2[i] - 'a' + 1);
            p[i] = p[i-1] * P;
        }
        for (int j = n; j >= 1; j --)
            hr[j] = hr[j+1] * P + (str2[j] - 'a' + 1);

        // 遍历回文中点，二分寻找最大半径r，O(nlogn)
        int ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            int l = 0, r = min(i-1, n-i);
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (HL(i, mid) != HR(i, mid)) r = mid - 1;
                else l = mid;
            }
            ans = max(ans, l);
        }
        cout << ans << endl;
    }
    return 0;
}