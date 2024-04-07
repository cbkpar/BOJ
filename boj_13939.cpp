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

	cin.ignore();
	string strWord;
	getline(cin, strWord);

	int iIndex = 0;
	int iLen = strWord.length();
	while (iIndex < iLen)
	{
		int iCount = 0;
		bool bFirst = true;
		bool bPossible = true;
		while (true)
		{
			if (strWord[iIndex] == '.' || strWord[iIndex] == '!' || strWord[iIndex] == '?')
			{
				if (bPossible) ++iCount;
				cout << iCount << "\n";
				iIndex += 2;
				break;
			}
			if (strWord[iIndex] >= 'a' && strWord[iIndex] <= 'z')
			{
				if (bFirst) bPossible = false;
			}
			if (strWord[iIndex] >= 'A' && strWord[iIndex] <= 'Z')
			{
				if (!bFirst) bPossible = false;
			}
			if (strWord[iIndex] >= '0' && strWord[iIndex] <= '9')
			{
				bPossible = false;
			}
			bFirst = false;
			if (strWord[iIndex] == ' ')
			{
				if (bPossible) ++iCount;
				bPossible = true;
				bFirst = true;
			}
			++iIndex;
		}

	}

	return 0;
}
