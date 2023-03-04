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
		int iN, iM;
		cin >> iN >> iM;
		vector<int> vecIndex(iN, 0);
		for (int i = 0; i < iN; ++i) vecIndex[iN - i - 1] = i;
		int iIndex = iN;
		while (iM--)
		{
			int iNum;
			cin >> iNum;
			vecIndex[iNum - 1] = iIndex++;
		}
		int iMin = 99999;
		int iMinIndex = -1;
		for (int i = 0; i < iN; ++i)
		{
			if (vecIndex[i] < iMin)
			{
				iMin = vecIndex[i];
				iMinIndex = i;
			}
		}
		cout << (iMinIndex + 1) << "\n";
	}

	return 0;
}
