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
	int strLen = strWord.length();

	int iN;
	cin >> iN;

	int iMaxLen = 1;
	int iMaxWeight = 0;
	string strAns = "No Jam";

	for (int i = 0; i < iN; ++i)
	{
		string strLine;
		cin >> strLine;

		int iWeight;
		cin >> iWeight;

		int iLen = strLine.length();
		int iNow = 0;
		for (int j = 0; j < iLen; ++j)
		{
			if (iNow < strLen && strWord[iNow] == strLine[j])
			{
				++iNow;
			}
		}

		if (iNow == strLen)
		{
			if (iMaxWeight * (iLen - strLen) < iWeight * iMaxLen)
			{
				iMaxLen = iLen - strLen;
				iMaxWeight = iWeight;
				strAns = strLine;
			}
		}
	}

	cout << strAns << "\n";
	return 0;
}
