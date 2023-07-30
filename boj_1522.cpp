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

	string strWord;
	cin >> strWord;

	int iCount = 0;
	string strTempWord = strWord + strWord;

	int iSize = strWord.length();
	for (int i = 0; i < iSize; ++i)
	{
		if (strWord[i] == 'a')
		{
			++iCount;
		}
	}

	int iAns = iCount;
	int iNowCount = 0;
	for (int i = 0; i < iCount; ++i)
	{
		if (strTempWord[i] == 'b')
		{
			++iNowCount;
		}
	}
	iAns = min(iAns, iNowCount);

	for (int i = iCount; i < iSize * 2; ++i)
	{
		if (strTempWord[i-iCount] == 'b')
		{
			--iNowCount;
		}
		if (strTempWord[i] == 'b')
		{
			++iNowCount;
		}
		iAns = min(iAns, iNowCount);
	}

	cout << iAns << "\n";
	return 0;
}
