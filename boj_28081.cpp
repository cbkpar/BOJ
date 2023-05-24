#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lW, lH, lK;
	cin >> lW >> lH >> lK;

	int iN, iM;

	cin >> iN;
	vector<long long> vecY(iN + 1, 0);
	long long lTemp = 0;
	for (int i = 0; i < iN; ++i)
	{
		long long lNum;
		cin >> lNum;
		vecY[i] = lNum - lTemp;
		lTemp = lNum;
	}
	vecY[iN] = lH - lTemp;

	cin >> iM;
	vector<long long> vecX(iM + 1, 0);
	lTemp = 0;
	for (int i = 0; i < iM; ++i)
	{
		long long lNum;
		cin >> lNum;
		vecX[i] = lNum - lTemp;
		lTemp = lNum;
	}
	vecX[iM] = lW - lTemp;


	sort(vecX.begin(), vecX.end());
	sort(vecY.begin(), vecY.end());

	long long lAns = 0;
	int iMaxIndex = iN;
	for (int i = 0; i <= iM; ++i)
	{
		while (iMaxIndex >= 0 && vecX[i] * vecY[iMaxIndex] > lK)
		{
			--iMaxIndex;
		}
		lAns += iMaxIndex + 1;
	}
	cout << lAns << "\n";
	return 0;
}
