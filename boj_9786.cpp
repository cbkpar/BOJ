#include <iostream>

using namespace std;

int gcd(int iA, int iB)
{
	if (iB % iA == 0) return iA;
	return gcd(iB % iA, iA);
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
		int iA, iB;
		cin >> iA >> iB;
		int iGCD = gcd(iA, iB);
		cout << (iA / iGCD) << " " << (iB / iGCD) << "\n";
	}

	return 0;
}
