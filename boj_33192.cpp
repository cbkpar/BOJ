#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 0;i < iN;++i)
	{
		long long lA, lB, lC;
		cin >> lA >> lB >> lC;
		lB -= lC;
		long long lTotal = (lA / 10) * ((lB * 10) + (lC * 20));
		if (lB >= 140)
		{
			lTotal += (lA / 10) * (lB - 140) * 5;
		}

		vector<long long> vecNum;
		while (lTotal > 0)
		{
			vecNum.push_back(lTotal % 1000);
			lTotal /= 1000;
		}
		if (vecNum.size() == 0) vecNum.push_back(0);

		int iLen = vecNum.size();
		for (int i = iLen - 1;i >= 0;--i)
		{
			if (i == iLen - 1)
			{
				printf("%ld", vecNum[i]);
			}
			else
			{
				printf("%03ld", vecNum[i]);
			}
			if (i == 0)
			{
				printf("\n");
			}
			else
			{
				printf(",");
			}
		}
	}

	return 0;
}
