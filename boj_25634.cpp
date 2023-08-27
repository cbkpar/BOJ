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

	vector<long long> vecLight(iN, 0);
	vector<long long> vecIsOn(iN, 0);

	for (int i = 0; i < iN; ++i) cin >> vecLight[i];
	for (int i = 0; i < iN; ++i) cin >> vecIsOn[i];

	int lSum = 0;
	for (int i = 0; i < iN; ++i) lSum += vecLight[i] * vecIsOn[i];

	long long lTempSum = 0;
	long long lPlus = vecLight[0] * (vecIsOn[0] == 1 ? -1 : 1);

	int iLeft = 0;
	int iRight = 0;
	while (iLeft <= iRight && iRight < iN)
	{
		while (iLeft < iN && lTempSum < 0)
		{
			if (vecIsOn[iLeft])
			{
				lTempSum += vecLight[iLeft];
			}
			else
			{
				lTempSum -= vecLight[iLeft];
			}
			++iLeft;
		}
		if (vecIsOn[iRight])
		{
			lTempSum -= vecLight[iRight];
		}
		else
		{
			lTempSum += vecLight[iRight];
		}
		++iRight;
		lPlus = max(lPlus, lTempSum);
	}

	cout << (lSum + lPlus) << "\n";
	return 0;
}
