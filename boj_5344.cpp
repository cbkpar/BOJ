#include <iostream>

using namespace std;

int gcd(int iA, int iB)
{
	if (iA % iB == 0) return iB;
	return gcd(iB, iA % iB);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	while (iN--)
	{
		int iA, iB;
		cin >> iA >> iB;
		if (iA > iB)
		{
			cout << gcd(iA, iB) << "\n";
		}
		else
		{
			cout << gcd(iB, iA) << "\n";
		}
	}
	return 0;
}
