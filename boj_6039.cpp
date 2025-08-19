#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lF, lM;
	int iN;
	cin >> lF >> lM >> iN;

	vector<pair<long long, long long>> vecData(iN, { 0,0 });
	for (int i = 0;i < iN;++i)
	{
		cin >> vecData[i].first >> vecData[i].second;
	}

	int iAns = 0;
	long long lAnsF = lF;
	long long lAnsM = lM;

	for (int i = 1;i < (1 << iN);++i)
	{
		long long lTempF = lF;
		long long lTempM = lM;
		int iTemp = i;
		for (int j = 0;j < iN;++j)
		{
			if (iTemp % 2 == 1)
			{
				lTempF += vecData[j].first;
				lTempM += vecData[j].second;
			}
			iTemp /= 2;
		}

		if (lTempF * lAnsM > lAnsF * lTempM)
		{
			iAns = i;
			lAnsF = lTempF;
			lAnsM = lTempM;
		}
	}

	if (iAns == 0)
	{
		cout << "NONE" << "\n";
	}
	else
	{
		int iTemp = iAns;
		for (int i = 1;i <= iN;++i)
		{
			if (iTemp % 2 == 1)
			{
				cout << i << "\n";
			}
			iTemp /= 2;
		}
	}

	return 0;
}
