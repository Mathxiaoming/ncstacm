#include <iostream>
#include <vector>
using namespace std;
 
const int N = 20010;
int seats[N];
 
int maxdis;
vector<int> ones; //记录全部1的位置
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> seats[i];    
    
    for(int i = 0; i < n; i ++ )
        if (seats[i]) ones.push_back(i);
    for(int i = 1; i < ones.size(); i ++ ) 
        maxdis = max((ones[i] - ones[i - 1]) / 2, maxdis);
    
    // 考虑边界情况
    int a = ones.front();
    int b = n - ones.back() - 1;
    cout << max(maxdis, max(a, b)) << endl;
}