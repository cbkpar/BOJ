#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH, iI, iA, iR, iC;
	cin >> iH >> iI >> iA >> iR >> iC;

	cout << (iH * iI - iA * iR * iC) << "\n";
	return 0;
}
