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

	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}

	vector<int> vecDiff(iN - 1, 0);
	for (int i = 0;i < iN - 1;++i)
	{
		vecDiff[i] = vecNum[i + 1] - vecNum[i] - 1;
	}

	sort(vecDiff.begin(), vecDiff.end(), greater<>());

	int iAns = vecNum[iN - 1] - vecNum[0] + 1;
	for (int i = 0;i < iK - 1;++i)
	{
		iAns -= vecDiff[i];
	}

	cout << iAns << "\n";
	return 0;
}
