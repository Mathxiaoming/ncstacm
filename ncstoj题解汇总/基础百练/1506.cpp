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
		for (int i = 0; i < str.size(); ++i)
		{
			// 大小写
			if (isupper(str[i]) && str[i] != 'I')
			{
				str[i] = tolower(str[i]);
			}
			// 预处理：把所有符号前加上空格，可以把符号和单词分开
			else if (!isalnum(str[i]))
			{
				str.insert(i, " "); 
				i++;
			}
			// ？-> ！
			if (str[i] == '?')
				str[i] = '!';
		}

		// 使用vector会有一个点段错误，后来发现如果这里使用string ans[1000]的形式就可以了。
		// 把预处理完的单词与符号全部加入ans数组中
		vector<string> ans;
		stringstream ss(str);

		while (ss >> str)
		{
			ans.push_back(str);
		}

		// 对于如果第一个字母是符号的特殊情况：符号前面本来是不需要加空格的，但是AI:后面必须加空格
		if (!isalnum(ans[0][0]))
			cout << " ";

		for (int i = 0; i < ans.size(); i++)
		{
			// 对于如果第一个字母是符号的特殊情况：符号前面不需要加空格
			if (!isalnum(ans[i][0]))
				cout << ans[i];

			else if (i + 1 < ans.size() && ans[i] == "can" && ans[i + 1] == "you")
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