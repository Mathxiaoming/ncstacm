// 题意：给出n种月饼的库存量和总价，在市场最大需求下，求最大利益

// 按每种月饼的单价（总价/库存量）降序排列

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1010;

struct Bing
{
    double val;  // 单价
    int maxval;  // 总价
    int maxw;  // 库存量
    bool operator<(const Bing &b) const {
        return val > b.val || (val == b.val && maxw < b.maxw);
    }
}bing[maxn];

int n, d;  // n种饼, 市场最大需求d
double ans;  

int main()
{
    freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    cin >> n >> d;
    for (int i = 0; i < n; i ++)
        cin >> bing[i].maxw;
    for (int i = 0; i < n; i ++)
    {
        cin >> bing[i].maxval;
        // 单价 = 总价 / 库存量
        bing[i].val = (double)bing[i].maxval/(double)bing[i].maxw;
    }
    sort(bing, bing + n);

    int cur = 0;  // 当前的饼编号
    while (cur < n)
    {
        //  cur号饼全用
        if (bing[cur].maxw < d)
        {
            d -= bing[cur].maxw;
            ans += bing[cur].maxval;
        }
        else
        {
            // 从bing[cur]中取d
            ans += (double)bing[cur].val * d;
            break;
        }
        cur ++;
    }
    printf("%.2f\n", ans);
    return 0;
}


