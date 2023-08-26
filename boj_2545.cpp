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
		vector<unsigned long long> vecLen(3, 0);
		for (int i = 0; i < 3; ++i) cin >> vecLen[i];
		sort(vecLen.begin(), vecLen.end());

		long long lN;
		cin >> lN;

		if (lN >= vecLen[2] - vecLen[1])
		{
			lN -= vecLen[2] - vecLen[1];
			vecLen[2] = vecLen[1];
		}
		else
		{
			vecLen[2] -= lN;
			lN = 0;
		}

		if (lN > 0 && lN >= (vecLen[1] - vecLen[0]) * 2ULL)
		{
			lN -= (vecLen[1] - vecLen[0]) * 2ULL;
			vecLen[2] = vecLen[1] = vecLen[0];
		}
		else
		{
			vecLen[1] -= (lN + 1) / 2;
			vecLen[2] -= lN / 2;
			lN = 0;
		}

		vecLen[0] -= (lN + 2) / 3;
		vecLen[1] -= (lN + 1) / 3;
		vecLen[2] -= (lN) / 3;
		cout << vecLen[0] * vecLen[1] * vecLen[2] << "\n";
	}

	return 0;
}
