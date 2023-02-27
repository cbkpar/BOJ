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
		int iN;
		cin >> iN;
		vector<int> vecCoin(iN, 0);
		for (int i = 0; i < iN; ++i) cin >> vecCoin[i];

		int iGoal;
		cin >> iGoal;
		vector<int> vecDP(iGoal + 1, 0);
		vecDP[0] = 1;
		for (int i = 0; i < iN; ++i)
		{
			for (int j = vecCoin[i]; j <= iGoal; ++j)
			{
				vecDP[j] += vecDP[j - vecCoin[i]];
			}
		}
		cout << vecDP[iGoal] << "\n";
	}

	return 0;
}
