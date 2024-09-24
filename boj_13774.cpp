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

	while (true)
	{
		string strWord;
		cin >> strWord;

		if (strWord == "#") break;

		int iLen = strWord.length();

		bool bPossible = false;
		int iIndex = -1;

		for (int i = 0;i < iLen;++i)
		{
			int iLeft = 0;
			int iRight = iLen - 1;

			bool bSame = true;
			while (iLeft < iRight)
			{
				if (i == iLeft) ++iLeft;
				if (i == iRight) --iRight;
				if (strWord[iLeft] != strWord[iRight])
				{
					bSame = false;
					break;
				}
				++iLeft;
				--iRight;
			}

			if (bSame)
			{
				iIndex = i;
				bPossible = true;
				break;
			}
		}

		if (bPossible)
		{
			for (int i = 0;i < iLen;++i)
			{
				if (i == iIndex) continue;
				cout << strWord[i];
			}
			cout << "\n";
		}
		else
		{
			cout << "not possible" << "\n";
		}
	}
	return 0;
}
