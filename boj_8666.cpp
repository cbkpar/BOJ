#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<int> vecCount(6, 0);
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		++vecCount[iNum - 1];
	}
	sort(vecCount.begin(), vecCount.end());

	int iType = 0;
	for (int i = 0; i < 6; ++i)
	{
		if (vecCount[i] > 0)
		{
			++iType;
		}
	}
	if (iType < iK)
	{
		cout << iK - iType << "\n";
		return 0;
	}

	int iAns = 0;
	for (int i = 0; i < 6 - iK; ++i)
	{
		iAns += vecCount[i];
	}

	cout << iAns << "\n";
	return 0;
}
