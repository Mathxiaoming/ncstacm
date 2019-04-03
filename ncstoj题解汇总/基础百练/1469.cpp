#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
 
int main()
{
    string s, ans, temp;
    getline(cin, s);
    reverse(s.begin(), s.end());
    stringstream ss(s);
    while (ss >> temp)
        ans = temp + " " + ans;
    cout << ans.substr(0, s.size()) << endl;
    return 0;
}