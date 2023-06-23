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
	vector<long long> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	vector<long long> vecCount(20, 0);
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if ((vecNum[i] & (1LL << j)) == (1LL << j))
			{
				++vecCount[j];
			}
		}
	}
	
	long long lSum = 0;
	for (int i = 0; i < 20; ++i)
	{
		lSum += (1LL << i) * (iN - vecCount[i]) * (vecCount[i]);
	}
	cout << lSum << "\n";
	return 0;
}
