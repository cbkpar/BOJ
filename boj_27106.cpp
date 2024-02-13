#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iP;
	cin >> iP;

	int iA, iB, iC, iD;

	iP = 100 - iP;

	iA = iP / 25;
	iP -= iA * 25;

	iB = iP / 10;
	iP -= iB * 10;

	iC = iP / 5;
	iP -= iC * 5;

	iD = iP;

	cout << iA << " " << iB << " " << iC << " " << iD << "\n";
	return 0;
}
