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
	while (iT-- > 0)
	{
		int iN;
		cin >> iN;
		vector<long long> vecNum(iN, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecNum[i];
		}
		sort(vecNum.begin(), vecNum.end());

		long long lAns = 0;
		if (iN >= 3)
		{
			long long lSum = vecNum[0] + vecNum[1];
			for (int i = 2;i < iN;++i)
			{
				if (lSum > vecNum[i])
				{
					lAns = max(lAns, lSum + vecNum[i]);
				}
				lSum += vecNum[i];
			}
		}
		cout << lAns << "\n";
	}


	return 0;
}
