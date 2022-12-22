#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	int iMax = 1;
	for (int i = 0; i < iN; ++i)
	{
		iMax *= 10;
	}

	int iCompare = 0;
	for (int i = 0; i < iM; ++i)
	{
		int iNumber;
		cin >> iNumber;
		iCompare |= (1 << iNumber);
	}

	int iAns = 0;
	for (int i = 0; i < iMax; ++i)
	{
		int iTemp = i;
		int iTempCompare = 0;
		for (int j = 0; j < iN; ++j)
		{
			int iTempNumber = iTemp % 10;
			iTemp /= 10;
			iTempCompare |= (1 << iTempNumber);
		}
		if ((iTempCompare & iCompare) == iCompare)
		{
			++iAns;
		}
	}
	cout << iAns << "\n";
	return 0;
}
