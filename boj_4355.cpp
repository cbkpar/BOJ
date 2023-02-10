#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;
		if (iN == 1)
		{
			cout << "0\n";
			continue;
		}

		int iSqrt = (int)sqrt(iN);
		int iAns = iN;
		for (int i = 2; i <= iSqrt; ++i)
		{
			if (iN % i == 0)
			{
				iAns /= i;
				iAns *= i - 1;
				while (iN % i == 0) iN /= i;
			}
		}
		if (iN != 1)
		{
			iAns /= iN;
			iAns *= iN - 1;
		}
		cout << iAns << "\n";

	}

	return 0;
}
