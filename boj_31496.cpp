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

	int iN;
	cin >> iN;

	string strWord;
	cin >> strWord;
	int iLen = strWord.length();

	int iSum = 0;
	while (iN--)
	{
		string strTemp;
		int iCount;
		cin >> strTemp >> iCount;

		bool bInclude = false;
		int iIndex = 0;
		for (char ch : strTemp)
		{
			if (ch == '_')
			{
				if (iIndex == iLen)
				{
					bInclude = true;
				}
				iIndex = 0;
			}
			else
			{
				if (iIndex == iLen) iIndex = -1;
				if (iIndex == -1) continue;
				if (strWord[iIndex] == ch)
				{
					++iIndex;
				}
				else
				{
					iIndex = -1;
				}
			}
		}
		if (iIndex == iLen)
		{
			bInclude = true;
		}
		if (bInclude)
		{
			iSum += iCount;
		}
	}

	cout << iSum << "\n";
	return 0;
}
