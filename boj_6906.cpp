#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	cin.ignore();
	while (iT--)
	{
		vector<string> vecWord(4, "");
		for (int i = 0; i < 4; ++i)
		{
			string strTemp;
			getline(cin, strTemp);
			string strWord = "";

			int iSize = strTemp.length();
			for (int j = iSize - 1; j >= 0; --j)
			{
				char ch = strTemp[j];
				if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
				if (strTemp[j] == ' ') break;
				if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
				{
					strWord += ch;
					break;
				}
				else
				{
					strWord += ch;
				}
			}
			vecWord[i] = strWord;
		}
		if (vecWord[0] == vecWord[1] && vecWord[1] == vecWord[2] && vecWord[2] == vecWord[3])
		{
			cout << "perfect" << "\n";
		}
		else if (vecWord[0] == vecWord[1] && vecWord[2] == vecWord[3])
		{
			cout << "even" << "\n";
		}
		else if (vecWord[0] == vecWord[2] && vecWord[1] == vecWord[3])
		{
			cout << "cross" << "\n";
		}
		else if (vecWord[0] == vecWord[3] && vecWord[1] == vecWord[2])
		{
			cout << "shell" << "\n";
		}
		else
		{
			cout << "free" << "\n";
		}
	}
	return 0;
}
