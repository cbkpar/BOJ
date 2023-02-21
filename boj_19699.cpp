#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline int BitCount(uint32_t i)
{
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (i + (i >> 4)) & 0x0F0F0F0F;
	return (i * 0x01010101) >> 24;
}

bool ArrPrime[9001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 9000; i++)
	{
		for (int j = i * i; j <= 9000; j += i)
		{
			ArrPrime[j] = true;
		}
	}

	int iN, iM;
	cin >> iN >> iM;
	vector<int> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	vector<int> vecAns;

	int iMax = 1 << iN;
	for (int i = 0; i < iMax; ++i)
	{
		if (BitCount(i) == iM)
		{
			int iSum = 0;
			for (int j = 0; j < iN; ++j)
			{
				if ((1 << j) & i)
				{
					iSum += vecNum[j];
				}
			}
			if (!ArrPrime[iSum])
			{
				ArrPrime[iSum] = true;
				vecAns.emplace_back(iSum);
			}
		}
	}
	sort(vecAns.begin(), vecAns.end());
	if (vecAns.empty())
	{
		cout << "-1\n";
	}
	else
	{
		int iSize = vecAns.size();
		for (int i = 0; i < iSize; ++i)
		{
			cout << vecAns[i] << (i == iSize - 1 ? "\n" : " ");
		}
	}

	return 0;
}
