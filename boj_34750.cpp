#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iA = 0;
	int iB = 0;
	int iT = iN / 100;

	if (iN >= 1000000)
	{
		iA = iT * 20;
		iB = iT * 80;
	}
	else if (iN >= 500000)
	{
		iA = iT * 15;
		iB = iT * 85;
	}
	else if (iN >= 100000)
	{
		iA = iT * 10;
		iB = iT * 90;
	}
	else
	{
		iA = iT * 5;
		iB = iT * 95;
	}

	cout << iA << " " << iB << "\n";
	return 0;
}
