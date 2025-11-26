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
	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}
	sort(vecNum.begin(), vecNum.end());

	int iAns = vecNum[0] - (vecNum[iN - 1] / 2);
	if (iAns < 0) iAns = 0;

	cout << iAns << "\n";
	return 0;
}
