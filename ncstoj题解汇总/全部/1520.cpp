#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    string s1, s2;
    unordered_set<int>set1;
    getline(cin, s1);
    getline(cin, s2);
    for (auto &c : s2) 
        if (c != ' ') set1.insert(c);
    for (auto &c : s1)
        if (!set1.count(c)) cout << c ;
    return 0;
}