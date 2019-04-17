#include <iostream>
#include <deque>
using namespace std;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
deque<int> q;
int pics[2010];
int a[maxn];
int n, m, cnt, ans = INF, ansl, ansr;
 
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if (!pics[a[i]]) cnt ++;
        q.push_back(i);
        pics[a[i]]++;
        while (pics[a[q.front()]] > 1)
        {
            pics[a[q.front()]] --;
            q.pop_front();
        }
        if (cnt == m && q.back()-q.front()+1 < ans)
        {
            ansl = q.front(), ansr = q.back();
            ans = ansr - ansl + 1;
        }
    }
    cout << ansl << " " << ansr << endl;
    return 0;
}