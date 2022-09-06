#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int iN, iLen;
int arrCount[26] = { 0, };
int arrNumber[20] = { 0, };

void dfs(int iK)
{
	if (iK == iLen)
	{
		for (int i = 0; i < iLen; ++i)
		{
			cout << char(arrNumber[i]+'a');
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (arrCount[i])
		{
			--arrCount[i];
			arrNumber[iK] = i;
			dfs(iK + 1);
			++arrCount[i];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strWord;
		cin >> strWord;
		iLen = strWord.length();
		memset(arrCount, 0, sizeof(int) * 26);
		for (int i = 0; i < iLen; ++i)
		{
			++arrCount[strWord[i] - 'a'];
		}
		dfs(0);
	}
	return 0;
}
