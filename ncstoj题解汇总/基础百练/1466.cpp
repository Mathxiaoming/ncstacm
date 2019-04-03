#include <iostream>
#include <algorithm>
using namespace std;
 
// 双指针
bool isPalindrome(int x) {
    if (x < 0) return false;
    string str = to_string(x);
    int i = 0, j = str.length() - 1;
    for ( ; i <= j; i ++, j -- )
        if (str[i] != str[j]) break;
    return i >= j;
}
 
// string
bool isPalindrome2(int x) {
    if (x < 0) return false;
    string str = to_string(x);
    string revstr(str);
    reverse(str.begin(), str.end());
    return str == revstr;
}
 
// 题目希望不把int转化为string来做
bool isPalindrome3(int x) {
    if (x < 0 || x % 10 == 0 && x != 0) return false;
    int halfRevNum = 0;
    while (x > halfRevNum) {
        halfRevNum = halfRevNum * 10 + x % 10;
        x /= 10;
    }
    return x == halfRevNum || x == halfRevNum/10;
}
 
int main() {
    int n;
    cin >> n;
    if (isPalindrome(n)) cout << "yes" << endl;
    // if (isPalindrome2(n)) cout << "yes" << endl;
    // if (isPalindrome3(n)) cout << "yes" << endl;
    else cout << "no" << endl;
}