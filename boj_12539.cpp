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
	for (int t = 1;t <= iT;++t)
	{
		int iMoney;
		cin >> iMoney;

		vector<int> vecA(12, 0);
		for (int i = 0;i < 12;++i)
		{
			cin >> vecA[i];
		}

		int iS = 0;
		int iE = 0;
		int iMaxMoney = 0;
		for (int i = 0;i < 12;++i)
		{
			for (int j = i + 1;j < 12;++j)
			{
				if (vecA[j] > vecA[i])
				{
					int iTemp = (iMoney / vecA[i]) * (vecA[j] - vecA[i]);
					if (iTemp <= 0) continue;
					if (iTemp > iMaxMoney)
					{
						iMaxMoney = iTemp;
						iS = i;
						iE = j;
					}
					else if (iTemp == iMaxMoney)
					{
						if (vecA[i] < vecA[iS])
						{
							iS = i;
							iE = j;
						}
					}
				}
			}
		}

		++iS;
		++iE;

		if (iMaxMoney == 0)
		{
			cout << "Case #" << t << ": IMPOSSIBLE" << "\n";
		}
		else
		{
			cout << "Case #" << t << ": " << iS << " " << iE << " " << iMaxMoney << "\n";
		}
	}
	return 0;
}
