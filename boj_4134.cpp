#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Add(long long lX, long long lY, long long lMod)
{
	lX %= lMod; lY %= lMod;
	if (lX + lY >= lMod) return lX + lY - lMod;
	return lX + lY;
}

long long Mul(long long lX, long long lY, long long lMod)
{
	lX %= lMod; lY %= lMod;
	long long lSum = 0;
	while (lY)
	{
		if (lY & 1) lSum = Add(lSum, lX, lMod);
		lX = Add(lX, lX, lMod);
		lY >>= 1;
	}
	return lSum;
}

long long Pow(long long lNum, long long lPow, long long lMod)
{
	long long lAns = 1;
	long long lTemp = lNum % lMod;
	while (lPow)
	{
		if (lPow & 1)
		{
			lAns = Mul(lAns, lTemp, lMod);
		}
		lTemp = Mul(lTemp, lTemp, lMod);
		lPow /= 2;
	}
	return lAns;
}

bool MillerCheck(long long n, long long a)
{
	if (a % n == 0) return true;
	long long k = n - 1;
	while (true)
	{
		long long temp = Pow(a, k, n);
		if (temp == n - 1) return true;
		if (k % 2 == 1) return (temp == 1 || temp == n - 1);
		k >>= 1;
	}
}

long long MillerNum[4] = { 2,7,37,61 };
bool Miller(long long n)
{
	for (int i = 0; i < 4; ++i)
	{
		if (n == MillerNum[i]) return true;
		if (!MillerCheck(n, MillerNum[i]))
		{
			return false;
		}
	}
	return true;
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
		long long lNum;
		cin >> lNum;
		if (lNum <= 2)
		{
			cout << "2\n";
			continue;
		}
		if (lNum % 2 == 0) ++lNum;
		while (true)
		{
			if (Miller(lNum))
			{
				cout << lNum << "\n";
				break;
			}
			lNum += 2;
		}
	}
	return 0;
}
