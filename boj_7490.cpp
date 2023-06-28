#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iN;
int arrOperator[10] = { 0, };

void dfs(int iK, long long lSum, long long lTemp, bool bMinus)
{
	if (iK == iN)
	{
		if (lSum + lTemp * (bMinus ? -1 : 1) == 0)
		{
			cout << "1";
			for (int i = 2; i <= iK; ++i)
			{
				if (arrOperator[i - 1] == 0) cout << "+";
				if (arrOperator[i - 1] == 1) cout << "-";
				if (arrOperator[i - 1] == 2) cout << " ";
				cout << i;
			}
			cout << "\n";
		}
		return;
	}
	arrOperator[iK] = 2;
	dfs(iK + 1, lSum, lTemp * 10 + iK + 1, bMinus);
	arrOperator[iK] = 0;
	dfs(iK + 1, lSum + lTemp * (bMinus ? -1 : 1), iK + 1, false);
	arrOperator[iK] = 1;
	dfs(iK + 1, lSum + lTemp * (bMinus ? -1 : 1), iK + 1, true);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 0; t < iT; ++t)
	{
		if (t > 0) cout << "\n";
		cin >> iN;
		dfs(1, 0, 1, false);
	}
	return 0;
}
