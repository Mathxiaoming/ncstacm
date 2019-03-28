#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> sta;
vector<int> v;

void push(int k)
{
    sta.push(k);
    auto it = lower_bound(v.begin(), v.end(), k);
    v.insert(it, k);
}

void pop()
{
    if (sta.empty())
        cout << "Invalid" << endl;
    else
    {
        cout << sta.top() << endl;
        auto it = lower_bound(v.begin(), v.end(), sta.top());
        v.erase(it);
        sta.pop();
    }
}
void peekmedian()
{
    if (sta.empty())
        cout << "Invalid" << endl;
    else
    {
        int tot = v.size();
        if (tot % 2 == 0)
            cout << v[tot / 2 - 1] << endl;
        else
            cout << v[tot / 2] << endl;
    }
}
int main()
{
    freopen("/Users/zhbink/Documents/C++/C++/in.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        char ops[15];
        scanf("%s", ops);
        if (ops[1] == 'u')
        {
            int key;
            cin >> key;
            push(key);
        }
        else if (ops[1] == 'o')
            pop();
        else
            peekmedian();
    }
    return 0;
}

// 线段树
// #include <iostream>
// #include <stack>
// using namespace std;
// int tree[maxn << 2];
// stack<int> sta;

// // 修改区间l~r，当前根节点rt，给x加num
// void update(int l, int r, int rt, int x, int num)
// {
//     if (l == r)
//     {
//         tree[rt] += num;
//         return;
//     }
//     int mid = (l + r) >> 1;
//     if (x <= mid)
//         update(l, mid, rt << 1, x, num);
//     else
//         update(mid + 1, r, rt << 1 | 1, x, num);
//     tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
// }


// int query(int l, int r, int rt, int x)
// {
//     if (l == r)
//         return l;
//     int mid = (l + r) >> 1;
//     if (tree[rt << 1] >= x)
//         return query(l, mid, rt << 1, x);
//     else
//         return query(mid + 1, r, rt << 1 | 1, x - tree[rt << 1]);
// }

// int main()
// {
//     int T;
//     cin >> T;
//     char ops[15];
//     while (T--)
//     {
//         scanf("%s", ops);
//         // pop
//         if (ops[1] == 'o')
//         {
//             if (sta.empty())
//                 printf("Invalid\n");
//             else
//             {
//                 int num = sta.top();
//                 sta.pop();
//                 printf("%d\n", num);
//                 update(0, 100000, 1, num, -1);
//             }
//         }
//         // peek
//         else if (ops[1] == 'e')
//         {
//             if (sta.empty())
//             {
//                 printf("Invalid\n");
//                 continue;
//             }
//             int n = sta.size();
//             if (n % 2)
//                 n = (n + 1) / 2;
//             else
//                 n = n / 2;
//             printf("%d\n", query(0, 100000, 1, n));
//         }
//         // push
//         else
//         {
//             int x;
//             scanf("%d", &x);
//             sta.push(x);
//             update(0, 100000, 1, x, 1);
//         }
//     }
//     return 0;
// }