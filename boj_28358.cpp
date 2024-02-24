#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arrDay[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecCount(1024, 0);
	for (int i = 1;i <= 12;++i)
	{
		for (int j = 1;j <= arrDay[i];++j)
		{
			int iBit = 0;
			int iTemp = i;
			while (iTemp)
			{
				int iNum = iTemp % 10;
				iTemp /= 10;
				iBit |= 1 << iNum;
			}
			iTemp = j;
			while (iTemp)
			{
				int iNum = iTemp % 10;
				iTemp /= 10;
				iBit |= 1 << iNum;
			}
			for (int k = 0;k < 1024;++k)
			{
				if ((k & iBit) == 0)
				{
					++vecCount[k];
				}
			}
		}
	}

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iBit = 0;
		for (int i = 0;i < 10;++i)
		{
			int iNum;
			cin >> iNum;
			if (iNum)
			{
				iBit |= 1 << i;
			}
		}
		cout << vecCount[iBit] << "\n";
	}
	return 0;
}
