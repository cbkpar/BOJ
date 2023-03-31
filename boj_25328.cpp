#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strA, strB, strC;
	cin >> strA >> strB >> strC;


	int iK;
	cin >> iK;

	int iLenA = strA.length();
	int iLenB = strB.length();
	int iLenC = strC.length();

	int iMaxA = 1 << iLenA;
	int iMaxB = 1 << iLenB;
	int iMaxC = 1 << iLenC;

	vector<string> vecAns;
	map<string, int> mapCount;
	string strTemp;
	strTemp.resize(iK);

	for (int i = 1; i < iMaxA; ++i)
	{
		int iCount = 0;
		int t = i;
		while (t)
		{
			if (t & 1) ++iCount;
			t /= 2;
		}

		if (iCount == iK)
		{
			int iIndex = 0;
			for (int j = 0; j < iLenA; ++j)
			{
				if ((i & (1 << j)) == (1 << j))
				{
					strTemp[iIndex++] = strA[j];
				}
			}
			mapCount[strTemp] = 1;
		}
	}

	for (int i = 1; i < iMaxB; ++i)
	{
		int iCount = 0;
		int t = i;
		while (t)
		{
			if (t & 1) ++iCount;
			t /= 2;
		}

		if (iCount == iK)
		{
			int iIndex = 0;
			for (int j = 0; j < iLenB; ++j)
			{
				if ((i & (1 << j)) == (1 << j))
				{
					strTemp[iIndex++] = strB[j];
				}
			}
			mapCount[strTemp] += 1;
			if (mapCount[strTemp] == 2)
			{
				vecAns.push_back(strTemp);
			}
		}
	}

	for (int i = 1; i < iMaxC; ++i)
	{
		int iCount = 0;
		int t = i;
		while (t)
		{
			if (t & 1) ++iCount;
			t /= 2;
		}

		if (iCount == iK)
		{
			int iIndex = 0;
			for (int j = 0; j < iLenC; ++j)
			{
				if ((i & (1 << j)) == (1 << j))
				{
					strTemp[iIndex++] = strC[j];
				}
			}
			mapCount[strTemp] += 1;
			if (mapCount[strTemp] == 2)
			{
				vecAns.push_back(strTemp);
			}
		}
	}
	if (vecAns.size() == 0)
	{
		cout << "-1\n";
		return 0;
	}
	sort(vecAns.begin(), vecAns.end());
	for (string strWord : vecAns)
	{
		cout << strWord << "\n";
	}
	return 0;
}
