#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<long long> vecA(iN);
	for (int i = 0; i < iN; ++i) cin >> vecA[i];
	vector<long long> vecB(iN);
	for (int i = 0; i < iN; ++i) cin >> vecB[i];

	map<long long, long long> mapCount;
	long long lAns = 0;

	long long lSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		long long lNum = vecB[i] - vecA[i];
		lSum += lNum;
		if (mapCount.find(lSum) != mapCount.end())
		{
			++mapCount[lSum];
		}
		else
		{
			mapCount.insert({ lSum,1 });
		}
		if (lSum == 0)
		{
			++lAns;
		}
	}
	for (const auto& iter : mapCount)
	{
		lAns += iter.second * (iter.second - 1) / 2;
	}
	cout << lAns << "\n";
	return 0;
}
