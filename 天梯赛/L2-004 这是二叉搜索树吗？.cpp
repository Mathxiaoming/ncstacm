// 按输入顺序进行建树，建树后和前序遍历、镜像前序遍历结果对比
// 如果在输入的时候同时建立一颗镜像树，则不用与镜像遍历结果对比

#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

// origin存放初始序列，pre、post为先序、后序，preM、postM为镜像树先序、后序序列
vector<int> origin, pre, preM, post, postM;

void insert(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if (data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

// 前序遍历
void preOrder(node *root)
{
    if (root == NULL)
        return;
    pre.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// 镜像前序遍历
void preOrderMirror(node *root)
{
    if (root == NULL)
        return;
    preM.push_back(root->data);
    preOrderMirror(root->right);
    preOrderMirror(root->left);
}

// 后序遍历
void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    post.push_back(root->data);
}

// 镜像后序遍历
void postOrderMirror(node *root)
{
    if (root == NULL)
        return;
    postOrderMirror(root->right);
    postOrderMirror(root->left);
    postM.push_back(root->data);
}

int main()
{
    freopen("/Users/zhbink/Documents/C++/C++/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n, data;
    node *root = NULL;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        origin.push_back(data);
        insert(root, data);
    }

    preOrder(root);
    preOrderMirror(root);
    postOrder(root);
    postOrderMirror(root);

    if (origin == pre)
    {
        cout << "YES" << endl;
        for (int i = 0; i < post.size(); i++)
            cout << post[i] << " \n"[i + 1 == post.size()];
    }
    else if (origin == preM)
    {
        cout << "YES" << endl;
        for (int i = 0; i < postM.size(); i ++)
            cout << postM[i] << " \n"[i + 1 == postM.size()];
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}


// 法2:在输入的时候同时建立一颗镜像树，则不用与镜像遍历结果对比
//挂了一个点，不知道为什么
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

// origin存放初始序列，pre、post为先序、后序，preM、postM为镜像树先序、后序序列
vector<int> origin, pre, preM, post, postM;

void insert(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if (data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

void insertM(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if (data > root->data)
        insertM(root->left, data);
    else
        insertM(root->right, data);
}

// 前序遍历
void preOrder(node *root, vector<int> &vi)
{
    if (root == NULL)
        return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

// 后序遍历
void postOrder(node *root, vector<int> &vi)
{
    if (root == NULL)
        return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}

int main()
{
    ios::sync_with_stdio(false);
    int n, data;
    node *root = NULL;
    node *rootM = NULL;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        origin.push_back(data);
        insert(root, data);
        insertM(rootM, data);
    }

    preOrder(root, pre);
    preOrder(rootM, preM);
    postOrder(root, post);
    postOrder(rootM, postM);

    if (origin == pre)
    {
        cout << "YES" << endl;
        for (int i = 0; i < post.size(); i++)
            cout << post[i] << " \n"[i + 1 == post.size()];
    }
    else if (origin == preM)
    {
        cout << "YES" << endl;
        for (int i = 0; i < postM.size(); i ++)
            cout << postM[i] << " \n"[i + 1 == postM.size()];
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}