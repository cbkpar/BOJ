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

	int iLeft = 0;
	int iRight = iLen - 1;
	while (iLeft < iRight)
	{
		if (strWord[iLeft] != '?' && strWord[iRight] != '?')
		{
			if (strWord[iLeft] != strWord[iRight])
			{
				cout << "0" << "\n";
				return 0;
			}
		}

		++iLeft;
		--iRight;
	}

	int iAns = 0;
	iLeft = 0;
	iRight = iLen - 1;
	while (iLeft < iRight)
	{
		if (strWord[iLeft] == '?' && strWord[iRight] == '?')
		{
			iAns += 26;
		}

		if (strWord[iLeft] == '?' && strWord[iRight] != '?')
		{
			iAns += 1;
		}

		if (strWord[iLeft] != '?' && strWord[iRight] == '?')
		{
			iAns += 1;
		}

		++iLeft;
		--iRight;
	}

	cout << iAns << "\n";

	return 0;
}
