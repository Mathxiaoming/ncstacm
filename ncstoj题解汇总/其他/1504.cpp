#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin.ignore();
		string str1, str2;
		getline(cin, str1, ',');
		getline(cin, str2, '.');
		stringstream ss1(str1), ss2(str2);

		string word1, word2;
		vector<string> v;
		while (ss1 >> word1);
		while (ss2 >> word2) v.push_back(word2);

		if (word1 == v.back())
		{
			string ans = str1 + ',';
			int n = v.size();
			for (int i = 0; i < n; i++)
			{
				if (i == n - 3) ans += " yes";
				else ans += " " + v[i];
			}
			cout << ans + "." << endl;
		}
		else
			cout << "no" << endl;
	}
	return 0;
}