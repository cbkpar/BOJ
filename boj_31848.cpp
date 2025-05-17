#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iNow = 0;

	vector<int> vecSize(iN + 1, 0);
	for (int i = 0; i < iN; ++i)
	{
		int iSize;
		cin >> iSize;

		int iMax = iSize + i;
		if (iMax > iN) iMax = iN;
		while (iNow <= iMax)
		{
			vecSize[iNow++] = i + 1;
		}
	}

	int iM;
	cin >> iM;
	for (int i = 0; i < iM; ++i)
	{
		int iSize;
		cin >> iSize;
		cout << vecSize[iSize] << (i == iM - 1 ? "\n" : " ");
	}

	return 0;
}
