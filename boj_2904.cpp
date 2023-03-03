#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Arrprime[1000001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	int iAns = 1;
	int iCount = 0;

	for (int i = 2; i * i <= 1000000; i++) {
		for (int j = i * i; j <= 1000000; j += i) {
			Arrprime[j] = true;
		}
	}
	for (int i = 2; i <= 1000000; ++i)
	{
		if (!Arrprime[i])
		{
			if (i < 1000)
			{
				int iSumCount = 0;
				vector<int> vecCount(iN, 0);
				for (int j = 0; j < iN; ++j)
				{
					int iTempNum = vecNum[j];
					while (iTempNum && iTempNum % i == 0)
					{
						++vecCount[j];
						++iSumCount;
						iTempNum /= i;
					}
				}
				iSumCount /= iN;
				if (iSumCount > 0)
				{
					for (int j = 0; j < iSumCount; ++j) iAns *= i;
					for (int j = 0; j < iN; ++j) if (vecCount[j] < iSumCount) iCount += iSumCount - vecCount[j];
				}
			}
			else
			{
				for (int j = 0; j < iN; ++j)
				{
					if (vecNum[j] % i != 0) break;
					if (j == iN - 1)
					{
						iAns *= i;
					}
				}
			}
		}
	}
	cout << iAns << " " << iCount << "\n";

	return 0;
}
