#include <iostream>

using namespace std;

long long GCD(long long lA, long long lB)
{
	if (lB%lA == 0) return lA;
	return GCD(lB%lA, lA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA, lB;
	cin >> lA >> lB;
	long long lGCD;
	if (lA > lB)
	{
		lGCD = GCD(lB, lA);
	}
	else
	{
		lGCD = GCD(lA, lB);
	}
	lA /= lGCD;
	lB/= lGCD;
	cout << (lA + lB - 1) * lGCD << "\n";
	return 0;
}
