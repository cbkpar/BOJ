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

	vector<int> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];
	sort(vecNum.begin(), vecNum.end());

	int iAns = 0;
	int iNum = -1;
	int iCount = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (vecNum[i] == iNum)
		{
			++iCount;
		}
		else
		{
			iNum = vecNum[i];
			iCount = 1;
		}
		iAns = max(iAns, iCount + min(iK, iN - 1 - i));
	}
	cout << iAns << "\n";

	return 0;
}
