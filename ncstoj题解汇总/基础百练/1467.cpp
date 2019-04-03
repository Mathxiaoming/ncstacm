#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;
 
stack<char> s1;
stack<char> s2;
unordered_set<char> set1{'(','[','{'};
unordered_map<char, char> map1{{')','('},{']','['},{'}','{'}};
string s;
 
bool isValid() {
    if (s.size() % 2) return false;
    for (auto c : s) {
        if (set1.count(c)) s1.push(c);
        else {
            if (s1.size() && s1.top() == map1[c]) s1.pop();
            else s2.push(c);
        }
    }
    return s1.empty() && s2.empty();
}
 
int main() {
    cin >> s;
    if (isValid()) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}