#include <iostream>
#include <vector>
#include <algorithm>

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

	long long lN, lA;
	cin >> lN >> lA;

	long long lS, lT;
	long long lGCD = exEuclid(lA, lN, lS, lT);
	cout << (lN - lA) << " " << (lGCD == 1 ? lS : -1) << "\n";
	return 0;
}
