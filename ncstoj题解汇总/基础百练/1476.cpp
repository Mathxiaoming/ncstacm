#include <iostream>
#include <algorithm>
// #include <sstream>
using namespace std;
 
// C++98
// string to_string(int n) {
//     string ret;
//     stringstream ss;
//     ss << n;
//     ss >> ret;
//     return ret;
// }
 
int main() {
    int a, b, d;
    cin >> a >> b >> d;
    int c = a + b;
    string ans;
    while (c) {
        ans += to_string(c % d);
        c /= d;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}