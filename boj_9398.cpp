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

	for (int i = 0;i < iN;++i)
	{
		string strLine;
		cin >> strLine;

		int iLeft = 0;
		int iRight = 0;
		int iLen = strLine.length();
		int iAns = 1000;
		vector<int> vecCount(3, 0);
		while (iRight < iLen)
		{
			if (iRight - iLeft < 6)
			{
				if (strLine[iRight] >= 'A' && strLine[iRight] <= 'Z') ++vecCount[0];
				if (strLine[iRight] >= 'a' && strLine[iRight] <= 'z') ++vecCount[1];
				if (strLine[iRight] >= '0' && strLine[iRight] <= '9') ++vecCount[2];
				++iRight;
			}
			else if (vecCount[0] > 0 && vecCount[1] > 0 && vecCount[2] > 0)
			{
				if (strLine[iLeft] >= 'A' && strLine[iLeft] <= 'Z') --vecCount[0];
				if (strLine[iLeft] >= 'a' && strLine[iLeft] <= 'z') --vecCount[1];
				if (strLine[iLeft] >= '0' && strLine[iLeft] <= '9') --vecCount[2];
				++iLeft;
			}
			else
			{
				if (strLine[iRight] >= 'A' && strLine[iRight] <= 'Z') ++vecCount[0];
				if (strLine[iRight] >= 'a' && strLine[iRight] <= 'z') ++vecCount[1];
				if (strLine[iRight] >= '0' && strLine[iRight] <= '9') ++vecCount[2];
				++iRight;
			}
			if (iRight - iLeft >= 6 && vecCount[0] > 0 && vecCount[1] > 0 && vecCount[2] > 0)
			{
				iAns = min(iAns, iRight - iLeft);
			}
		}
		while (iLeft < iRight - 6)
		{
			if (strLine[iLeft] >= 'A' && strLine[iLeft] <= 'Z') --vecCount[0];
			if (strLine[iLeft] >= 'a' && strLine[iLeft] <= 'z') --vecCount[1];
			if (strLine[iLeft] >= '0' && strLine[iLeft] <= '9') --vecCount[2];
			++iLeft;

			if (iRight - iLeft >= 6 && vecCount[0] > 0 && vecCount[1] > 0 && vecCount[2] > 0)
			{
				iAns = min(iAns, iRight - iLeft);
			}
		}
		if (iAns == 1000) iAns = 0;
		cout << iAns << "\n";
	}


	return 0;
}
