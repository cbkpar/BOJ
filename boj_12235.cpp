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
		int iN, iX;
		cin >> iN >> iX;

		vector<int> vecSize(iN, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecSize[i];
		}
		sort(vecSize.begin(), vecSize.end());

		vector<bool> vecUsed(iN, false);
		int iAns = 0;
		for (int i = iN - 1;i >= 0;--i)
		{
			if (vecUsed[i])
			{
				continue;
			}
			++iAns;
			vecUsed[i] = true;
			for (int j = i - 1;j >= 0;--j)
			{
				if (vecUsed[j])
				{
					continue;
				}
				if (vecSize[i] + vecSize[j] <= iX)
				{
					vecUsed[j] = true;
					break;
				}
			}
		}
		cout << "Case #" << t << ": " << iAns << "\n";
	}

	return 0;
}
