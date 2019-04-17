#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

const int maxn = 1010;
int nums1[maxn], nums2[maxn];  // nums1是nums2的子集
stack<int> stk;
unordered_map<int, int> h;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> nums1[i];
    for (int i = 0; i < m; i ++) cin >> nums2[i];

    for (int i = m-1; ~i; --i)
    {
        int x = nums2[i];
        while (stk.size() && stk.top() < x) stk.pop();
        h[x] = stk.size() ? stk.top() : -1;
        stk.push(x);
    }
    
    for (int i = 0; i < n; i ++) cout << h[nums1[i]] << " ";
    return 0;
}