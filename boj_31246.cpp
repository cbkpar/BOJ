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
		int iA, iB;
		cin >> iA >> iB;
		vecNum[i] = iB - iA;
	}

	sort(vecNum.begin(), vecNum.end());
	int iAns = vecNum[iK - 1];
	if (iAns < 0) iAns = 0;

	cout << iAns << "\n";
	return 0;
}
