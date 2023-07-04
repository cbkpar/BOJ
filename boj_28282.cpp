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

	vector<long long> vecCountLeft(iK + 1, 0);
	vector<long long> vecCountRight(iK + 1, 0);

	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		++vecCountLeft[iNum];
	}
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		++vecCountRight[iNum];
	}
	long long lSum = 0;
	for (int i = 1; i <= iK; ++i)
	{
		lSum += vecCountLeft[i] * (iN - vecCountRight[i]);
	}
	cout << lSum << "\n";
	return 0;
}
