#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	vector<double> vecMax(iN, 0);
	for (int i = 0; i < iM; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			int iNum;
			double dAmount;
			cin >> iNum >> dAmount;
			vecMax[iNum - 1] = max(vecMax[iNum - 1], dAmount);
		}
	}
	sort(vecMax.begin(), vecMax.end(), greater<double>());

	double dAns = 0.0;
	for (int i = 0; i < iK; ++i)
	{
		dAns += vecMax[i];
	}

	printf("%.1lf\n", dAns);
	return 0;
}
