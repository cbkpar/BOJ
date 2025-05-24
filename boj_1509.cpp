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
	int iLen = strWord.length();

	vector<char> vecChar(iLen * 2 + 1, '#');
	for (int i = 0; i < iLen; ++i)
	{
		vecChar[i * 2 + 1] = strWord[i];
	}

	vector<int> vecLen(iLen * 2 + 1, 0);
	int iR = 0;
	int iP = 0;

	for (int i = 0; i < iLen * 2 + 1; ++i)
	{
		if (iR > i)
		{
			vecLen[i] = min(vecLen[2 * iP - i], iR - i);
		}

		while (i - vecLen[i] - 1 >= 0 && i + vecLen[i] + 1 <= iLen * 2 &&
			vecChar[i - vecLen[i] - 1] == vecChar[i + vecLen[i] + 1])
		{
			++vecLen[i];
		}

		if (iR < i + vecLen[i])
		{
			iR = i + vecLen[i];
			iP = i;
		}
	}

	vector<int> vecCount(iLen * 2 + 1, 1e9);
	vecCount[0] = 0;
	for (int i = 0; i < iLen * 2 + 1; ++i)
	{
		for (int j = vecLen[i]; j > 0; --j)
		{
			vecCount[i + j] = min(vecCount[i + j], vecCount[i - j] + 1);
		}
	}

	cout << vecCount[iLen * 2] << "\n";
	return 0;
}
