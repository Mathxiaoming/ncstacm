#include <cstdio>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, m, a;
    cin >> n >> k >> m;
    vector<float> ans;
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        vector<int> num;
        for (int j = 0; j < k; ++j)
        {
            cin >> a;
            num.push_back(a);
        }
        sort(num.begin(), num.end());
        sum = accumulate(num.begin() + 1, num.end() - 1, 0);
        ans.push_back(sum * (1.0) / (k - 2));
    }
    sort(ans.begin(), ans.end());
    for (int i = n - m; i < ans.size(); ++i)
        printf("%.3f%c", ans[i], " \n"[i == ans.size() - 1]);
    return 0;
}
