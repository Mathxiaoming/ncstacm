#include <queue>
#include <vector>
#include <iostream>
using namespace std;
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
const int maxn = 50;
//存放前序，中序遍历的结点
vector<int> fir(maxn), mid(maxn);

struct tree //存放树
{
    int l, r;
} tree[maxn];

int buildTree(int fl, int fr, int ml, int mr) //先序，中序遍历的初始结束位置
{
    if (ml > mr) //如果左子树的左大于右，说明没有子节点
        return 0;
    int root = fir[fl], p1 = ml, p2;
    while (mid[p1] != root)
        ++p1; //找到根
    p2 = p1 - ml; //左子树的个数
    tree[root].l = buildTree(fl + 1, fl + p2, ml, p1 - 1); //递归建立左子树
    tree[root].r = buildTree(fl + p2 + 1, fr, p1 + 1, mr); //递归建立右子树
    return root;
}

void bfs(int r)
{
    queue<int> q;
    vector<int> ans;
    q.push(r);
    while (!q.empty())
    {
        int root = q.front();
        q.pop();
        if (root == 0)
            break; //如果树空
        ans.push_back(root);
        if (tree[root].r) //要求镜面反转，所以先加右子树
            q.push(tree[root].r);
        if (tree[root].l)
            q.push(tree[root].l);
    }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> mid[i];
    for (int i = 0; i < n; ++i)
        cin >> fir[i];
    int root = buildTree(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}
