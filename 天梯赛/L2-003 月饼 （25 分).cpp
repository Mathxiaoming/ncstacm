// 题意：给出n种月饼的库存量和总价，在市场最大需求下，求最大利益
// 按每种月饼的单价（总价/库存量）降序排列

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;

struct Bing
{
    double val; // 单价
    double maxval; // 总价
    double maxw;   // 库存量
    bool operator<(const Bing &b) const
    {
        return val > b.val;
    }
} bing[maxn];

int n;  // n种饼,
double d;  // 市场最大需求d
double ans;  // 最终答案
double totw, totval;  // 总重、总价值，用于判断总重小于最大需求d的情况（加个这个判断快一点）

int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> bing[i].maxw;
    for (int i = 0; i < n; i++)
    {
        cin >> bing[i].maxval;
        // 单价 = 总价 / 库存量
        bing[i].val = bing[i].maxval / bing[i].maxw;
        totw += bing[i].maxw;
        totval += bing[i].maxval;
    }
    sort(bing, bing + n);

    if (totw <= d)
        ans = totval;
    else
    {
        int cur = 0; // 当前的饼编号
        while (1)
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
                ans += bing[cur].val * d;
                break;
            }
            cur++;
        }
    }

    printf("%.2f\n", ans);
    return 0;
}
