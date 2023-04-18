#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long binomial[2001][2001] = { 0, };
long long lMod;

void InitComb()
{
	for (int i = 0; i <= lMod; ++i)
	{
		binomial[i][0] = 1;
		for (int j = 1; j <= i; ++j)
		{
			binomial[i][j] = (binomial[i - 1][j - 1] + binomial[i - 1][j]) % lMod;
		}
	}
}

long long Lucas(long long n, long long m)
{
	long long lRet = 1;
	while (n || m)
	{
		lRet = (lRet * binomial[n % lMod][m % lMod]) % lMod;
		n /= lMod;
		m /= lMod;
	}
	return lRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lK;
	cin >> lN >> lK >> lMod;
	InitComb();
	
	cout << Lucas(lN, lK) << "\n";
	return 0;
}
