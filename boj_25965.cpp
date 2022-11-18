#include <iostream>

using namespace std;

long long arrCost[100][3];

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
		for (int i = 0; i < iN; ++i)
		{
			cin >> arrCost[i][0] >> arrCost[i][1] >> arrCost[i][2];
		}
		int iKill, iDeath, iAssist;
		cin >> iKill >> iDeath >> iAssist;
		long long lTotalCost = 0;
		for (int i = 0; i < iN; ++i)
		{
			long long lTempCost = 0;
			lTempCost += arrCost[i][0] * iKill;
			lTempCost -= arrCost[i][1] * iDeath;
			lTempCost += arrCost[i][2] * iAssist;
			if (lTempCost > 0)
			{
				lTotalCost += lTempCost;
			}
		}
		cout << lTotalCost << "\n";
	}
	return 0;
}
