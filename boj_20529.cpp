#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long CalcDist(int iType1, int iType2)
{
	long long lDist = 0;
	for (int k = 0; k < 4; ++k)
	{
		if (iType1 % 2 != iType2 % 2) ++lDist;
		iType1 /= 2;
		iType2 /= 2;
	}
	return lDist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		long long lAns = 1000000;
		vector<long long> vecCount(16, 0);

		int iN;
		cin >> iN;
		while (iN--)
		{
			string strType;
			cin >> strType;
			int iType = 0;
			if (strType[0] == 'I') iType += 1 << 3;
			if (strType[1] == 'N') iType += 1 << 2;
			if (strType[2] == 'T') iType += 1 << 1;
			if (strType[3] == 'P') iType += 1 << 0;
			++vecCount[iType];
		}
		for (int i = 0; i < 16; ++i)
		{
			if (vecCount[i] == 0) continue;
			--vecCount[i];
			for (int j = 0; j < 16; ++j)
			{
				if (vecCount[j] == 0) continue;
				--vecCount[j];
				for (int k = 0; k < 16; ++k)
				{
					if (vecCount[k] == 0) continue;
					--vecCount[k];
					long long lSum = 0;
					lSum += CalcDist(i, j);
					lSum += CalcDist(j, k);
					lSum += CalcDist(k, i);
					lAns = min(lAns, lSum);
					++vecCount[k];
				}
				++vecCount[j];
			}
			++vecCount[i];
		}
		cout << lAns << "\n";
	}
	return 0;
}
