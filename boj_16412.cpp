#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iL, iR;
	cin >> iL >> iR;

	int iAns = 0;
	for (int i = iL;i <= iR;++i)
	{
		int iN = i;
		vector<int> vecCount(10, 0);
		while (iN > 0)
		{
			vecCount[iN % 10]++;
			iN /= 10;
		}

		bool bPossible = true;
		if (vecCount[0] >= 1) bPossible = false;
		for (int j = 1;j < 10;++j)
		{
			if (vecCount[j] > 1) bPossible = false;
			if (vecCount[j] == 1 && (i % j != 0)) bPossible = false;
		}
		if (bPossible)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
