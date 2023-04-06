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
	iN /= 2;

	vector<vector<long long>> vecDP(2, vector<long long>(iN + 1, 0));
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecDP[0][i] >> vecDP[1][i];
		vecDP[0][i] += vecDP[0][i - 1];
		vecDP[1][i] += vecDP[1][i - 1];
	}
	long long lAns = vecDP[0][iN];
	for (int i = 1; i <= iN; ++i)
	{
		lAns = max(lAns, vecDP[0][i] + vecDP[1][iN - 1] - vecDP[1][i - 1]);
		lAns = max(lAns, vecDP[0][i - 1] + vecDP[1][iN] - vecDP[1][i - 1]);
	}
	cout << lAns << "\n";
	return 0;
}
