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

	int iT;
	cin >> iT;
	while (iT--)
	{
		long long lNumber;
		cin >> lNumber;
		--lNumber;

		long long matAnswer[2][2] = { {1,0},{0,1} };
		long long matDouble[2][2] = { {1,1},{1,0} };

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
						matAnswer[i][j] = (matTemp[i][j]) % 1000000000;
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
					matDouble[i][j] = (matTemp[i][j]) % 1000000000;
				}
			}
			lNumber /= 2;
		}
		cout << (matAnswer[1][0] + matAnswer[1][1]) % 1000000000 << "\n";
	}
	return 0;
}
