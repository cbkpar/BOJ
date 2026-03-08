#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<long long> vecS(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecS[i];
	}

	long long lAns = vecS[0];
	long long lSum = vecS[0];
	for (int i = 1;i < iN;++i)
	{
		if (vecS[i] > lSum)
		{
			lAns = max(lAns, vecS[i] - lSum);
		}
		lSum += vecS[i];
	}

	cout << lAns << "\n";
	return 0;
}
