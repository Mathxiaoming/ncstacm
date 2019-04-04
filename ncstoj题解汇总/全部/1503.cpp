#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> v;

int str2int(string str)
{
	stringstream ss(str);
	int ret;
	ss >> ret;
	return ret;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end());

	int ans = 1440;
	for (int i = 1; i < n; i++)
	{
		int h = str2int(v[i].substr(0, 2)) * 60, m = str2int(v[i].substr(3, 2));
		int lh = str2int(v[i - 1].substr(0, 2)) * 60, lm = str2int(v[i - 1].substr(3, 2));
		if (h + m - lh - lm < ans)
			ans = h + m - lh - lm;
	}
	int h = (str2int(v[0].substr(0, 2)) + 24) * 60, m = str2int(v[0].substr(3, 2));
	int lh = str2int(v[n - 1].substr(0, 2)) * 60, lm = str2int(v[n - 1].substr(3, 2));
	if (h + m - lh - lm < ans)
		ans = h + m - lh - lm;

	cout << ans << endl;
	return 0;
}