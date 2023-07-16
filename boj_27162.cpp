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

	vector<int> vecCount(7, 0);
	for (int i = 0; i < 3; ++i)
	{
		int iNum;
		cin >> iNum;
		++vecCount[iNum];
	}

	int iAns = 0;

	for (int p = 1; p <= 6; ++p)
	{
		for (int q = 1; q <= 6; ++q)
		{
			++vecCount[p];
			++vecCount[q];

			for (int i = 0; i < 6; ++i)
			{
				if (strWord[i] == 'Y')
				{
					int iTemp = 0;
					iAns = max(iAns, vecCount[i + 1] * (i + 1));
				}
			}
			if (strWord[6] == 'Y')
			{
				for (int i = 1; i <= 6; ++i)
				{
					if (vecCount[i] >= 4)
					{
						iAns = max(iAns, i * 4);
					}
				}
			}
			if (strWord[7] == 'Y')
			{
				for (int i = 1; i <= 6; ++i)
				{
					for (int j = 1; j <= 6; ++j)
					{
						if (i == j) continue;
						if (vecCount[i] >= 3 && vecCount[j] >= 2)
						{
							iAns = max(iAns, vecCount[i] * i + vecCount[j] * j);
						}

					}
				}
			}
			if (strWord[8] == 'Y')
			{
				bool bStraight = true;
				for (int i = 1; i <= 5; ++i)
				{
					if (vecCount[i] == 0) bStraight = false;
				}
				if (bStraight)
				{
					iAns = max(iAns, 30);
				}
			}
			if (strWord[9] == 'Y')
			{
				bool bStraight = true;
				for (int i = 2; i <= 6; ++i)
				{
					if (vecCount[i] == 0) bStraight = false;
				}
				if (bStraight)
				{
					iAns = max(iAns, 30);
				}
			}
			if (strWord[10] == 'Y')
			{
				for (int i = 1; i <= 6; ++i)
				{
					if (vecCount[i] == 5)
					{
						iAns = max(iAns, 50);
					}
				}
			}
			if (strWord[11] == 'Y')
			{
				int iTemp = 0;
				for (int i = 1; i <= 6; ++i)
				{
					iTemp += vecCount[i] * i;
				}
				iAns = max(iAns, iTemp);
			}

			--vecCount[p];
			--vecCount[q];
		}
	}
	cout << iAns << "\n";
	return 0;
}
