#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
 
const int N = 10050;
int n, a[N];
unordered_set<int> set1;
 
int main () {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        int k;
        cin >> k;
        set1.insert(k);
    }
    cout << min((int)set1.size(), n / 2) << endl;
    return 0;
}