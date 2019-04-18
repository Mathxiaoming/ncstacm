#include <cstdio>
#include <vector>
using namespace std;

using ll = long long;
const int p = 1e5+3;  // p可以是任意比较大的素数，太小(如131)会相当于普通数组导致超时
vector<vector<int> > head[p+5];

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
        int x = 0;
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &a[j]);
            // 哈希：取模，注意乘法要避免溢出
            x = (x + (ll)a[j] * a[j] % p) % p;
        }

        // 邻接表存储每个雪花的信息，可以把查找的时间降到O(1)
        // 对于每一个在相同表头head[x]的元素，他们6个数的和取模后都为x

        // 遍历表头head[x]指向的链表，寻找形状相同的雪花
        for (int j = 0; j < head[x].size(); j++)
            if (isEqual(a, head[x][j]))
            {
                puts("Twin snowflakes found.");
                return 0;
            }
        head[x].push_back(a);
    }
    puts("No two snowflakes are alike.");
    return 0;
}