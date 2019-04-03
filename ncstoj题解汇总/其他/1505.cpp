#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
 
int main()
{
	int N;
	cin >> N;
	cin.ignore();
	while (N--)
	{
		string str;
		getline(cin, str);
		cout << str << endl << "AI:";
		vector<string> ans;
		stringstream ss(str);
 
		while (ss >> str)
		{
			ans.push_back(str);
		}
 
		for (int i = 0; i < ans.size(); i++)
		{
			if (i + 1 < ans.size() && ans[i] == "can" && ans[i + 1] == "you")
			{
				cout << " I can";
				i++;
			}
			else if (i + 1 < ans.size() && ans[i] == "could" && ans[i + 1] == "you")
			{
				cout << " I could";
				i++;
			}
			else if (ans[i] == "I" || ans[i] == "me")
				cout << " you";
			else
				cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}