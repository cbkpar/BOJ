#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vecNumber;
	int iN, iM;
	cin >> iN >> iM;
	for (int i = 0; i < iN; ++i)
	{
		int iInput;
		cin >> iInput;
		vecNumber.push_back(iInput);
	}
	sort(vecNumber.begin(), vecNumber.end());
	int iLeft = 0;
	int iRight = 0;
	int iMinDiff = 2100000000;
	while (iRight < iN && iLeft <= iRight)
	{
		int iDiff = vecNumber[iRight] - vecNumber[iLeft];
		if (iM <= iDiff)
		{
			if (iMinDiff > iDiff)
			{
				iMinDiff = iDiff;
			}
			++iLeft;
		}
		else
		{
			++iRight;
		}
	}
	cout << iMinDiff << endl;
	return 0;
}
