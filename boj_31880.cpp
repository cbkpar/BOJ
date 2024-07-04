#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	long long lAns = 0;
	vector<long long> vecN(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecN[i];
	}
	vector<long long> vecM(iM, 0);
	for (int i = 0;i < iM;++i)
	{
		cin >> vecM[i];
	}

	for (int i = 0;i < iN;++i)
	{
		lAns += vecN[i];
	}
	for (int i = 0;i < iM;++i)
	{
		if (vecM[i] > 1)
		{
			lAns *= vecM[i];
		}
	}

	cout << lAns << "\n";
	return 0;
}
