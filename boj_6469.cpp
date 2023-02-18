#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

	int iA, iB;
	bool bIsFirst = true;

	while (cin >> iA >> iB) {
		int iGCD = iA < iB ? gcd(iA, iB) : gcd(iB, iA);
		if (!bIsFirst) cout << "\n";
		cout.width(10); cout << iA;
		cout.width(10); cout << iB;
		cout << (iGCD == 1 ? " Good Choice\n" : " Bad Choice\n");
		bIsFirst = false;
	}

	return 0;
}
