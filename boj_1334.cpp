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

	string strNum;
	cin >> strNum;

	int iSize = strNum.length();
	for (int i = 0; i < iSize; ++i)
	{
		if (strNum[i] != '9') break;
		if (i == iSize - 1)
		{
			cout << "1";
			for (int j = 0; j < iSize - 1; ++j)
			{
				cout << "0";
			}
			cout << "1\n";
			return 0;
		}
	}
	vector<int> vecNum(iSize, 0);
	for (int i = 0; i < iSize; ++i) vecNum[iSize - 1 - i] = strNum[i] - '0';
	++vecNum[0];
	for (int i = 0; i < iSize - 1; ++i) {
		if (vecNum[i] >= 10)
		{
			vecNum[i + 1] += vecNum[i] / 10;
			vecNum[i] %= 10;
		}
	}
	if (iSize % 2 == 0)
	{
		int iMid = iSize / 2;
		for (int i = 0; i < iSize / 2; ++i)
		{
			int iLeft = iMid + i;
			int iRight = iMid - i - 1;
			if (vecNum[iLeft] == vecNum[iRight]) continue;
			if (vecNum[iLeft] > vecNum[iRight])
			{
				for (int j = 0; j < iSize / 2; ++j)
				{
					vecNum[iMid - j - 1] = vecNum[iMid + j];
				}
				break;
			}
			else
			{
				++vecNum[iMid];
				for (int j = 0; j < iSize - 1; ++j) {
					if (vecNum[j] >= 10)
					{
						vecNum[j + 1] += vecNum[j] / 10;
						vecNum[j] %= 10;
					}
				}
				for (int j = 0; j < iSize / 2; ++j)
				{
					vecNum[iMid - j - 1] = vecNum[iMid + j];
				}
				break;
			}
		}
	}
	else
	{
		int iMid = iSize / 2;
		for (int i = 1; i <= iSize / 2; ++i)
		{
			int iLeft = iMid + i;
			int iRight = iMid - i;
			if (vecNum[iLeft] == vecNum[iRight]) continue;
			if (vecNum[iLeft] > vecNum[iRight])
			{
				for (int j = 1; j <= iSize / 2; ++j)
				{
					vecNum[iMid - j] = vecNum[iMid + j];
				}
				break;
			}
			else
			{
				++vecNum[iMid];
				for (int j = 0; j < iSize - 1; ++j) {
					if (vecNum[j] >= 10)
					{
						vecNum[j + 1] += vecNum[j] / 10;
						vecNum[j] %= 10;
					}
				}
				for (int j = 1; j <= iSize / 2; ++j)
				{
					vecNum[iMid - j] = vecNum[iMid + j];
				}
				break;
			}
		}
	}
	for (int i = iSize - 1; i >= 0; --i) cout << vecNum[i];
	cout << "\n";

	return 0;
}
