#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int matCount[4][14] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWord;
	cin >> strWord;

	int iLen = strWord.length() / 3;
	for (int i = 0;i < iLen;++i)
	{
		char chType = strWord[i * 3];
		int iX = strWord[i * 3 + 1] - '0';
		int iY = strWord[i * 3 + 2] - '0';

		int iType = 0;
		int iNum = iX * 10 + iY;

		if (chType == 'P') iType = 0;
		if (chType == 'K') iType = 1;
		if (chType == 'H') iType = 2;
		if (chType == 'T') iType = 3;

		if (matCount[iType][iNum] > 0)
		{
			cout << "GRESKA" << "\n";
			return 0;
		}
		++matCount[iType][iNum];

	}

	for (int i = 0;i < 4;++i)
	{
		int iSum = 13;
		for (int j = 1;j <= 13;++j)
		{
			iSum -= matCount[i][j];
		}
		cout << iSum << (i == 3 ? "\n" : " ");
	}
	return 0;
}
