// 长度为5000的字符串，如果用O(n^2)的代码会超时，需要一遍扫描解决问题。
 
// 如子串 “0001111”，有3个0和4个1，则可以组成min(3,4) = 3个对称子串
// “01”
// “0011”
// “000111”
 
// 再如字符串”0110001111”
// 先考虑子串”011”，可以组成1个对称子串。 现在0已经没有价值了。
// 再考虑子串“11000”，可以组成2个对称子串。 现在1已经没有价值了。
// 再考虑子串“0001111”，可以组成3个对称子串。
// 所以一共可以组成6个子串。
 
// 时间复杂度O(n)
 
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    int ans = 0;
    string s;
    cin >> s;
    int sum1 = 0, sum2 = 1;
    for (int i = 1; i < s.length(); i ++ ) {
        if (s[i-1] != s[i]) {
            ans += min(sum1, sum2);
            sum1 = sum2;
            sum2 = 1;
        }
        else sum2 ++;
    }
    cout << ans + min(sum1, sum2) << endl;
    return 0;  
}