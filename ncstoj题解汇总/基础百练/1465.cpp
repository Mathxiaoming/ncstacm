// 练一下二进制与十进制的相互转化，如果本题数据范围扩大，用int存储中间变量decimal会溢出，需要使用string存储中间变量。
#include <iostream>
#include <algorithm>
using namespace std;
 
int BinaryToDecimal(string num) {
    int ret = 0;
    int n = num.length();
    for (int i = 0; i < n; i ++ )
        if (num[n - i - 1] != '0') ret += 1 << i; //ret += pow(2, i); 要引入cmath
    return ret;
}
 
string DecimaltoBinary(int num){
    string ret = "";
    while (num) {
        if(num & 1) ret += '1';
        else ret += '0';
        num >>= 1;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
 
int main()
{
    string a, b;
    cin >> a >> b;
    int decimal = BinaryToDecimal(a) + BinaryToDecimal(b);
    cout << DecimaltoBinary(decimal) << endl;
    return 0;
}