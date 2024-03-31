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
	while (iT--)
	{
		string strWord;
		cin >> strWord;

		int iLen = strWord.length();
		int iNum = 0;
		int iPos = 0;
		for (int i = 0;i < iLen;++i)
		{
			if (strWord[i] != '!')
			{
				iNum = strWord[i] - '0';
				iPos = i;
			}
		}

		if (iPos != iLen - 1) iNum = 1;
		if (iPos % 2 == 1) iNum = (iNum + 1) % 2;

		cout << iNum << "\n";
	}
	return 0;
}
