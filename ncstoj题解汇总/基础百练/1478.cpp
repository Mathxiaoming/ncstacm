#include <unordered_set>
#include <iostream>
using namespace std;
 
const int N = 105;
int nums1[N], nums2[N];
 
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) cin >> nums1[i];
    for (int i = 0; i < m; i ++ ) cin >> nums2[i];
    unordered_set<int> hash(nums1, nums1 + n);
   
    for (int i = 0; i < m; i ++ )
        if (hash.erase(nums2[i]))
            cout << nums2[i] << " ";
    return 0;
}