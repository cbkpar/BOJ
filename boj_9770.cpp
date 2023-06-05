#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long lA, long long lB)
{
	if (lB % lA == 0) return lA;
	return gcd(lB % lA, lA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> vecNum;
	long long lNum;
	while (cin >> lNum)
	{
		vecNum.push_back(lNum);
	}
	int iSize = vecNum.size();
	long long lAns = 0;
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = i + 1; j < iSize; ++j)
		{
			lAns = max(lAns, gcd(vecNum[i], vecNum[j]));
		}
	}
	cout << lAns << "\n";
	return 0;
}
