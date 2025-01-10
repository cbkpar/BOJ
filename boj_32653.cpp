#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long gcd(long long a, long long b)
{
	if (b % a == 0) return a;
	return gcd(b % a, a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	long long lAns = 1;

	for (int i = 0;i < iN;++i)
	{
		long long lNum;
		cin >> lNum;
		lNum *= 2;

		long long lgcd = gcd(lNum, lAns);
		lAns /= lgcd;
		lAns *= lNum;
	}

	cout << lAns << "\n";
	return 0;
}
