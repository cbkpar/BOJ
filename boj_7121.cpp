#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long lA, long long lB)
{
	if (lB % lA == 0)
	{
		return lA;
	}
	else
	{
		return gcd(lB % lA, lA);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA, lB, lC;
	cin >> lA >> lB >> lC;
	++lA;
	++lB;

	long long lLCM = lA * lB / gcd(lA, lB);
	long long lAnsC = lC / lB;
	long long lAnsD = lC / lA;
	long long lAnsB = lC / lLCM;
	lAnsC -= lAnsB;
	lAnsD -= lAnsB;
	long long lAnsA = lC - lAnsB - lAnsC - lAnsD;

	cout << lAnsA << " ";
	cout << lAnsB << " ";
	cout << lAnsC << " ";
	cout << lAnsD << "\n";

	return 0;
}
