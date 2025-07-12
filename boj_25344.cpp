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
	long long lGCD = 1;
	for (int i = 0; i < iT - 2; ++i)
	{
		long long lNum;
		cin >> lNum;
		long long lTempGCD = gcd(lGCD, lNum);
		lGCD *= lNum / lTempGCD;
	}

	cout << lGCD << "\n";
	return 0;
}
