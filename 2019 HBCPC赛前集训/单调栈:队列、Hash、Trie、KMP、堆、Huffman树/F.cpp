#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
 
int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        int n;
        cin >> n;
        priority_queue<int> max_heap, min_heap;
 
        int cnt = 0;
        for (int i = 0; i < n; i ++ )
        {
            int t;
            cin >> t;
            max_heap.push(t);
            if (min_heap.size() && -min_heap.top() < max_heap.top())
            {
                int a = -min_heap.top(), b = max_heap.top();
                min_heap.pop(), max_heap.pop();
                min_heap.push(-b), max_heap.push(a);
            }
 
            if (max_heap.size() > min_heap.size() + 1)
            {
                min_heap.push(-max_heap.top());
                max_heap.pop();
            }

            if (!(i & 1))
                printf("%d ", max_heap.top());
        }
    }
    return 0;
}