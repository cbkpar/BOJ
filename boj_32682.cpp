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
		int iNum;
		cin >> iNum;

		bool bOdd = false;
		bool bSquare = false;

		int iSqrt = (int)sqrt(iNum);

		if (iNum % 2 == 1) bOdd = true;
		if (iSqrt * iSqrt == iNum) bSquare = true;

		if (!bOdd && !bSquare)
		{
			cout << "EMPTY" << "\n";
		}
		else
		{
			if (bOdd) cout << "O";
			if (bSquare) cout << "S";
			cout << "\n";
		}
	}

	return 0;
}
