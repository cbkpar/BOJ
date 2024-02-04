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
	for (int i = 0;i < iN;++i) cin >> vecNum[i];

	int iPos = -1;
	int iMax = -1;
	for (int i = 0;i < iN;++i)
	{
		if (vecNum[i] > iMax)
		{
			iMax = vecNum[i];
			iPos = i;
		}
	}

	int iLeft = 0;
	int iRight = 0;
	for (int i = 0;i < iPos;++i) iLeft += vecNum[i];
	for (int i = iPos+1;i < iN;++i) iRight += vecNum[i];

	cout << iLeft << "\n";
	cout << iRight << "\n";
	return 0;
}
