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
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	sort(vecNum.begin(), vecNum.end());
	long long lYang = 0;
	long long lPark = 0;

	int iLeft = 0;
	int iRight = iN - 1;
	while (true)
	{
		lPark += vecNum[iRight--];
		if (iLeft > iRight) break;
		lYang += vecNum[iLeft++];
		if (iLeft > iRight) break;
	}
	cout << lYang << " " << lPark << "\n";
	return 0;
}
