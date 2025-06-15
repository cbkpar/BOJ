#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;
	vector<long long> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecNum[i];
	}

	sort(vecNum.begin(), vecNum.end());

	long long lAns = 0;
	for (int i = 0; i < (iK + 1) / 2; ++i)
	{
		lAns += vecNum[iN - i] - vecNum[i];
	}

	cout << lAns << "\n";
	return 0;
}
