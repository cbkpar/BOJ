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
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}

	long long lAns = 0;
	long long lMax = 100000000;
	for (int i = iN - 1;i >= 0;--i)
	{
		lMax = min(lMax, vecNum[i]);
		lAns += lMax;
	}

	cout << lAns << "\n";
	return 0;
}
