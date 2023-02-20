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

	vector<long long> vecC(6);
	for (int i = 0; i < 6; ++i) cin >> vecC[i];

	long long lGCD1 = gcd(vecC[0], vecC[4]);
	long long lGCD2 = gcd(vecC[2], vecC[5]);

	cout << (vecC[0] / lGCD1) << " " << lGCD1 << " " << (vecC[4] / lGCD1) << " ";
	cout << (vecC[5] / lGCD2) << " " << lGCD2 << " " << (vecC[2] / lGCD2) << "\n";

	return 0;

}
