#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 35;

int pos[maxn], pre[maxn];
int N;

struct node
{
    int val;
    node *lchild, *rchild;
};

// 后序区间左右端点Lpos, Rpos; 中序遍历左右端点Lin, Rin
node* build(int Lpos, int Rpos, int Lin, int Rin)
{
    if (Lpos > Rpos) return NULL;
    
    node *root = new node;
    root->val = pos[Rpos];

    // k为根在中序遍历中的位置
    // 中序遍历中，[k]为根；[Lin, k-1]为左子树；[k+1,Rin]为右子树
    int k = Lin;
    while (pre[k] != root->val) k++;

    // 左子树长度
    int left = k - Lin;

    // 后序遍历中，[Rpos]为根；[Lpos, Lpos+left-1]为左子树；[Lpos+left, Rpos-1]为右子树
    root -> lchild = build(Lpos, Lpos + left - 1, Lin, k - 1);
    root -> rchild = build(Lpos + left, Rpos - 1, k + 1, Rin);
    return root;
}

// 层序遍历：bfs
void bfs(node *root)
{
    vector<int> ans;
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node *head = q.front();
        ans.push_back(head->val);
        q.pop();
        if (head->lchild) q.push(head->lchild);
        if (head->rchild) q.push(head->rchild);
    }
    for (int i = 0; i < N; i ++ ) cout << ans[i] << " \n"[i==N-1];
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i ++ ) cin >> pos[i];
    for (int i = 0; i < N; i ++ ) cin >> pre[i];
    
    node *root = new node;
    root = build(0, N-1, 0, N-1);

    bfs(root);

    return 0;
}