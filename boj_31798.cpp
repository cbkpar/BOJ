#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	if (iA == 0)
	{
		cout << (iC * iC - iB) << "\n";
	}

	if (iB == 0)
	{
		cout << (iC * iC - iA) << "\n";
	}

	if (iC == 0)
	{
		cout << sqrt(iA + iB) << "\n";
	}
	return 0;
}
