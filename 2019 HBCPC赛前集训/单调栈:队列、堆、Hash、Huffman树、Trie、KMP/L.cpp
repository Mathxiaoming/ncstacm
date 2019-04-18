#include <cstdio>
#include <vector>
using namespace std;

using ll = long long;
const int p = 1e5+3;  // p可以是任意比较大的素数，太小(如131)会相当于普通数组导致超时
vector<vector<int> > head[p+5];

// 求雪花a的哈希值
int H(vector<int> a)
{
    // 对于6个数都相同的雪花，他们6个数之和、6个数之积都应该相等
    // 构造的哈希方法很多
    // 比如：
    int sum = 0, mul = 1;
    for (int i = 0; i < 6; i ++)
    {
        sum = (sum + a[i]) % p;
        mul = (ll)mul * a[i] % p;
    }
    return (sum + mul) % p;

    //或者
    // int mul = 1;
    // for (int i = 0; i < 6; i ++)
    //     mul = (ll)mul * a[i] % p;
    // return mul;

    //或者
    // int sum = 0;
    // for (int i = 0; i < 6; i ++)
    //     sum = (sum + a[i]) % p;
    // return sum;

    //或者
    // int sum = 0, mul = 1;
    // for (int i = 0; i < 6; i ++)
    // {
    //     sum = (sum + a[i]) % p;
    //     mul = (ll)mul * a[i] % p;
    // }
    // return ((ll)sum * mul) % p;
}

// 判断两个向量正逆序之一是否相同
// 1 2 3 4 5 6
// 4 3 2 1 6 5
bool isEqual(vector<int> a, vector<int> b)
{
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
        {
            // 正序
            bool flag = 1;
            for (int k = 0; k < 6; k++)
                if (a[(i + k) % 6] != b[(j + k) % 6])
                {
                    flag = 0;
                    break;
                }
            if (flag)
                return 1;
            
            // 逆序
            flag = 1;
            for (int k = 0; k < 6; k++)
                if (a[(i + k) % 6] != b[(j - k + 6) % 6])
                {
                    flag = 0;
                    break;
                }
            if (flag)
                return 1;
        }
    return 0;
}

int main()
{
    // freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        vector<int> a(6);
        int val = 0;
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &a[j]);
            // 哈希：取模，注意乘法要避免溢出
            // val = (val + (ll)a[j] * a[j] % p) % p;  // 可以代替下面一行的 通过函数求哈希值
        }
        val = H(a);

        // 邻接表存储每个雪花的信息，可以把查找的时间降到O(1)
        // 对于每一个在相同表头head[val]的元素，他们6个数都相同，只需要看6个数是否满足正逆序之一相同的条件

        // 遍历表头head[val]指向的链表，寻找形状相同的雪花
        for (int j = 0; j < head[val].size(); j++)
            if (isEqual(a, head[val][j]))
            {
                puts("Twin snowflakes found.");
                return 0;
            }
        head[val].push_back(a);
    }
    puts("No two snowflakes are alike.");
    return 0;
}