#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}

	int iMaxLen = 1;
	long long lMaxSum = vecNum[0];

	int iLen = 1;
	long long lSum = vecNum[0];

	for (int i = 1;i < iN;++i)
	{
		if (vecNum[i] >= vecNum[i - 1])
		{
			++iLen;
			lSum += vecNum[i];

			if (iLen > iMaxLen)
			{
				iMaxLen = iLen;
				lMaxSum = lSum;
			}
		}
		else
		{
			iLen = 1;
			lSum = vecNum[i];
		}
	}

	cout << iMaxLen << " " << lMaxSum << "\n";
	return 0;
}
