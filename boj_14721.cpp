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
	vector<pair<long long, long long>> vecPos(iN, { 0,0 });
	pair<long long, long long> pAns = { 0,0 };
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
	}

	long long lMax = 1LL << 62;

	for (long long i = 1; i <= 100; ++i)
	{
		for (long long j = 1; j <= 100; ++j)
		{
			long long lSum = 0;
			for (int k = 0; k < iN; ++k)
			{
				long long diff = (vecPos[k].first * i + j - vecPos[k].second);
				lSum += diff * diff;
			}
			if (lSum < lMax)
			{
				lMax = lSum;
				pAns.first = i;
				pAns.second = j;
			}
		}
	}
	cout << pAns.first << " " << pAns.second << "\n";
	return 0;
}
