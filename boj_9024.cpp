#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN, iK;
		cin >> iN >> iK;

		vector<int> vecPlus;
		vector<int> vecMinus;

		for (int i = 0; i < iN; ++i)
		{
			int iNum;
			cin >> iNum;
			iNum = iNum * 2 - iK;
			if (iNum >= 0)
			{
				vecPlus.push_back(iNum);
			}
			else
			{
				vecMinus.push_back(iNum);
			}
		}

		int iSizePlus = vecPlus.size();
		int iSizeMinus = vecMinus.size();
		if (iSizePlus == 0 || iSizeMinus == 0)
		{
			cout << "1\n";
			continue;
		}

		sort(vecPlus.begin(), vecPlus.end());
		sort(vecMinus.begin(), vecMinus.end(), greater<>());
		int iDiff = 2000000001;

		int iPlus = 0;
		int iMinus = 0;
		int iAns = 0;
		while (true)
		{
			if (iPlus >= iSizePlus) break;
			if (iMinus >= iSizeMinus) break;
			int iSum = vecPlus[iPlus] + vecMinus[iMinus];
			if (iSum >= 0)
			{
				++iMinus;
			}
			else
			{
				++iPlus;
			}
			if (iDiff == abs(iSum))
			{
				++iAns;
			}
			else if (iDiff > abs(iSum))
			{
				iDiff = abs(iSum);
				iAns = 1;
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
