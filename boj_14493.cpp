#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lT = 0;

	int iN;
	cin >> iN;
	while (iN--)
	{
		long long lA, lB;
		cin >> lA >> lB;

		long long lTemp = lT % (lA + lB);
		if (lTemp < lB)
		{
			lT += lB - lTemp;
		}
		++lT;
	}
	cout << lT << "\n";
	return 0;
}
