#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		long long lN, lM, lK, lD;
		cin >> lN >> lM >> lK >> lD;

		long long lB = (lD * 2) / (lN * lM * (lK * (lM - 1) + (lN - 1) * lM));
		long long lAns = (lN * lM * lB) * (lK * (lM - 1) + (lN - 1) * lM) / 2;
		if (lB <= 0)
		{
			cout << "-1\n";
		}
		else
		{
			cout << lAns << "\n";
		}
	}

	return 0;
}
