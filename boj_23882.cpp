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

	int iCount = iK;

	vector<int> vecNumber(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNumber[i];
	for (int i = 0; i < iN; ++i)
	{
		int iIndex = -1;
		int iMax = -1;
		for (int j = 0; j < iN - i; ++j)
		{
			if (vecNumber[j] > iMax)
			{
				iMax = vecNumber[j];
				iIndex = j;
			}
		}
		if (iIndex != iN - i - 1)
		{
			swap(vecNumber[iN - i - 1], vecNumber[iIndex]);
			--iCount;
		}
		if (iCount == 0)
		{
			for (int i = 0; i < iN; ++i)
			{
				cout << vecNumber[i] << (i == iN - 1 ? "\n" : " ");
			}
			return 0;
		}
	}
	cout << "-1\n";

	return 0;
}
