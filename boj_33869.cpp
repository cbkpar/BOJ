#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWord;
	cin >> strWord;

	string strKey;
	cin >> strKey;

	set<char> setChar;
	int iNow = 0;
	vector<char> vecChar(26, ' ');
	for (char ch : strWord)
	{
		if (setChar.find(ch) == setChar.end())
		{
			setChar.insert(ch);
			vecChar[iNow++] = ch;
		}
	}

	for (int i = 0; i < 26; ++i)
	{
		if (setChar.find('A'+i) == setChar.end())
		{
			vecChar[iNow++] = (char)('A' + i);
		}
	}
	
	for (char ch : strKey)
	{
		cout << vecChar[ch-'A'];
	}
	cout << "\n";
	return 0;
}
