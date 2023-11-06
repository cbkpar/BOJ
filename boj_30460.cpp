#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	vector<long long> vecNum(iN + 3, 0);
	vector<long long> vecDP(iN + 3, 0);
	long long lSum = 0;

	for (int i = 1;i <= iN;++i)
	{
		cin >> vecNum[i];
		lSum += vecNum[i];
	}

	for (int i = 3;i <= iN + 2;++i)
	{
		vecDP[i] = max(vecDP[i - 1], vecDP[i - 3] + vecNum[i - 2] + vecNum[i - 1] + vecNum[i]);
	}

	long long lAns = lSum + vecDP[iN + 2];
	cout << lAns << "\n";
	return 0;
}
