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

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iN;
		cin >> iN;
		int iSqrt = (int)sqrt(iN);
		if (iN == iSqrt * iSqrt)
		{
			cout << "1" << "\n";
		}
		else
		{
			cout << "0" << "\n";
		}
	}

	return 0;
}
