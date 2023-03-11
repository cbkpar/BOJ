#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool ArrPrime[100001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 100000; i++) {
		for (int j = i * i; j <= 100000; j += i) {
			ArrPrime[j] = true;
		}
	}
	vector<int> vecPrime;
	for (int i = 2; i <= 100000; ++i)
	{
		if (!ArrPrime[i])
		{
			vecPrime.push_back(i);
		}
	}
	int iSize = vecPrime.size();

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;

		int iAns = 0;
		int iIndex = 0;
		for (int i = 0; i < iSize; ++i)
		{
			if (iN < vecPrime[i]) break;
			int iTemp = iN;
			iIndex = i;
			while (iTemp)
			{
				iAns += iTemp / vecPrime[i];
				iTemp /= vecPrime[i];
			}
		}
		cout << (iIndex + 1) << " " << iAns << "\n";
	}
	return 0;
}
