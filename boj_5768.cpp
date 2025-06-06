#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecCount(5001, 0);
	for (int i = 1; i <= 5000; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (i % j == 0)
			{
				++vecCount[i];
			}
		}
	}

	while (true)
	{
		int iN, iM;
		cin >> iN >> iM;

		if (iN == 0 && iM == 0) break;

		int iAnsNum = -1;
		int iAnsCount = -1;
		for (int i = iN; i <= iM; ++i)
		{
			if (iAnsCount <= vecCount[i])
			{
				iAnsNum = i;
				iAnsCount = vecCount[i];
			}
		}
		cout << iAnsNum << " " << iAnsCount << "\n";
	}
	return 0;
}
