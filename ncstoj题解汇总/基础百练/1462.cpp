// 二分查找 时间复杂度O(logn)
// 二分查找有模版，自己可以在网上找一个自己觉得好的
 
// 旋转数组中的nums[0]是数组中的特殊元素，在旋转之前的升序数组中，它前面的数都是比它小的，它后面的数都是比它大的。
// 旋转数组中要二分找的点p满足这样的条件：p点之前的点都大于nums[0]，p点之后的点都小于nums[0]
 
#include <iostream>
#include <algorithm>
using namespace std;
 
const int N = 110;
int nums[N];
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> nums[i];
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;  // int mid = l + r >> 1;
        if (nums[mid] <= nums[0]) r = mid; 
        else l = mid + 1;
    }
    cout << nums[l] << endl;
    return 0;
}