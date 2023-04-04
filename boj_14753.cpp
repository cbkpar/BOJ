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
	vector<long long> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];
	sort(vecNum.begin(), vecNum.end());

	long long lAns = vecNum[0] * vecNum[1];

	lAns = max(lAns, vecNum[0] * vecNum[1]);
	lAns = max(lAns, vecNum[0] * vecNum[1] * vecNum[iN - 1]);
	lAns = max(lAns, vecNum[iN - 1] * vecNum[iN - 2] * vecNum[iN - 3]);
	lAns = max(lAns, vecNum[iN - 1] * vecNum[iN - 2]);

	cout << lAns << "\n";
	return 0;
}
