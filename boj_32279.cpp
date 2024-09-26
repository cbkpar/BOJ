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
	vector<long long> vecNum(iN + 1, 0);

	long long lP, lQ, lR, lS;
	cin >> lP >> lQ >> lR >> lS;

	cin >> vecNum[1];
	for (int i = 2;i <= iN;++i)
	{
		if (i % 2 == 0)
		{
			vecNum[i] = vecNum[i / 2] * lP + lQ;
		}
		else
		{
			vecNum[i] = vecNum[i / 2] * lR + lS;
		}
	}

	long long lSum = 0;
	for (int i = 1;i <= iN;++i)
	{
		lSum += vecNum[i];
	}

	cout << lSum << "\n";
	return 0;
}
