#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

vector<string> v;

string findcompre()
{
	for (int i = 0; i < v[0].size(); i++)
	{
		char c = v[0][i];
		for (int j = 1; j < v.size(); j++)
		{
			if (c != v[j][i] || i == v[j].size())
			{
				if (!i) return "NONE";
				return v[0].substr(0, i);
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		v.clear();
		int n;
		cin >> n;
		while (n--)
		{
			string str;
			cin >> str;
			v.push_back(str);
		}

		cout << findcompre() << endl;
	}
	return 0;
}