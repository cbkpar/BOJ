#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

long long exEuclid(long long a, long long b, long long& s, long long& t)
{
	if (b == 0) { s = 1; t = 0; return a; }
	long long gcd = exEuclid(b, a % b, s, t);
	swap(s, t);
	t -= (a / b) * s;

	if (s <= 0)
	{
		s += b;
		t -= a;
	}
	return gcd;
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
		long long lK, lC;
		cin >> lK >> lC;

		long long lAns = 0;
		if (lC == 1)
		{
			lAns = lK + 1;
		}
		else
		{
			long long lX, lY;
			long long lGCD = exEuclid(lK, lC, lX, lY);
			if (lGCD != 1)
			{
				lAns = 2000000000;
			}
			else
			{
				lAns = (((lX * (lC - 1)) % lC) * lK + 1) / lC;
			}
		}
		if (lAns > 1000000000)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			cout << lAns << "\n";
		}
	}
	return 0;
}
