#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

char arrChar[5] = { 'A','E','I','O','U' };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	string strWord;
	cin >> strWord;
	stack<char> stChar;

	bool bPossible = false;
	int iLevel = 0;
	for (int i = iN - 1;i >= 0;--i)
	{
		if (iLevel == 0)
		{
			for (int j = 0;j < 5;++j)
			{
				if (strWord[i] == arrChar[j])
				{
					break;
				}
				if (j == 4)
				{
					stChar.push(strWord[i]);
					iLevel = 1;
				}
			}
		}
		else if (iLevel == 1 || iLevel == 2)
		{
			if (strWord[i] == 'A')
			{
				stChar.push(strWord[i]);
				++iLevel;
			}
		}
		else if (iLevel < iM)
		{
			stChar.push(strWord[i]);
			++iLevel;
		}
	}

	if (iLevel == iM)
	{
		cout << "YES" << "\n";
		while (!stChar.empty())
		{
			cout << stChar.top();
			stChar.pop();
		}
		cout << "\n";

	}
	else
	{
		cout << "NO" << "\n";
	}

	return 0;
}
