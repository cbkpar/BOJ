#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ArrPrime[1000001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 1000000; i++) {
		for (int j = i * i; j <= 1000000; j += i) {
			ArrPrime[j] = true;
		}
	}
	ArrPrime[0] = ArrPrime[1] = true;

	int iN;
	cin >> iN;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	int iCount = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iSum = vecNum[i];
		for (int j = i + 1; j < iN; ++j)
		{
			iSum += vecNum[j];
			if (!ArrPrime[j - i + 1] && !ArrPrime[iSum])
			{
				++iCount;
			}
		}
	}
	cout << iCount << "\n";
	return 0;
}
