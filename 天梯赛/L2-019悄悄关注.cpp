#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
int main()
{
    int n;
    cin >> n;
    string str;
    unordered_map<string, int> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        m[str] = 0;
    }

    int k, val, sum = 0;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> str >> val;
        if (m.count(str)) //如果关注了，值为正，否则为负
            m[str] = val;
        else
            m[str] = (-1) * val;
        sum += val;
    }
    
    set<string> ans;
    int ave = sum / k;    
    for (auto it : m)
        if (it.second < 0 && it.second * (-1) > ave) //没关注并且值大于平均值
            ans.insert(it.first);

    if (ans.empty())
        cout << "Bing Mei You" << endl;
    else
        for (string s : ans)
            cout << s << endl;
    return 0;
}