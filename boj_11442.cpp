#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long CalcFibo(long long lN)
{
	if (lN <= 2) return 1;
	--lN;
	vector<vector<long long>> matFibo(2, vector<long long>(2, 0));
	vector<vector<long long>> matPow(2, vector<long long>(2, 0));
	matFibo[0][0] = matFibo[1][1] = 1;
	matPow[0][0] = matPow[0][1] = matPow[1][0] = 1;
	while (lN)
	{
		if (lN & 1)
		{
			vector<vector<long long>> matTemp(2, vector<long long>(2, 0));
			for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) matTemp[i][j] += matFibo[i][k] * matPow[k][j];
			for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) matFibo[i][j] = (matTemp[i][j]) % 1000000007;
		}
		vector<vector<long long>> matTemp(2, vector<long long>(2, 0));
		for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) matTemp[i][j] += matPow[i][k] * matPow[k][j];
		for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) matPow[i][j] = (matTemp[i][j]) % 1000000007;
		lN /= 2;
	}
	return (matFibo[1][0] + matFibo[1][1]) % 1000000007;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN;
	cin >> lN;
	if (lN % 2 == 0) --lN;

	cout << CalcFibo(lN + 1) << "\n";
	return 0;
}
