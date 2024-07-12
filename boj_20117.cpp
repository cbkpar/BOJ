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

	vector<long long> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}
	sort(vecNum.begin(), vecNum.end());

	long long lAns = 0;

	int iS = 0;
	int iE = iN - 1;
	while (iS <= iE)
	{
		if (iS != iE)
		{
			lAns += vecNum[iE] * 2;
		}
		else
		{
			lAns += vecNum[iE];
		}
		++iS;
		--iE;
	}

	cout << lAns << "\n";
	return 0;
}
