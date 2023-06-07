#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long lA, long long lB)
{
	if (lB % lA == 0) return lA;
	return gcd(lB % lA, lA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lM;
	cin >> lN >> lM;

	long long lGCD = gcd(lN, lM);

	long long matAnswer[2][2] = { {1,0},{0,1} };
	long long matDouble[2][2] = { {1,1},{1,0} };

	long long lNumber = lGCD - 1;
	while (lNumber)
	{
		if (lNumber % 2 == 1)
		{
			long long matTemp[2][2] = { 0, };
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					for (int k = 0; k < 2; ++k)
					{
						matTemp[i][j] += matDouble[i][k] * matAnswer[k][j];
					}
				}
			}
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					matAnswer[i][j] = (matTemp[i][j]) % 1000000007;
				}
			}
		}
		long long matTemp[2][2] = { 0, };
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int k = 0; k < 2; ++k)
				{
					matTemp[i][j] += matDouble[i][k] * matDouble[k][j];
				}
			}
		}
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				matDouble[i][j] = (matTemp[i][j]) % 1000000007;
			}
		}
		lNumber /= 2;
	}
	cout << (matAnswer[1][0] + matAnswer[1][1]) % 1000000007 << "\n";
	return 0;
}
