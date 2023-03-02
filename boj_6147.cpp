#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iB;
	cin >> iN >> iB;
	vector<int> arrHeight(iN);
	for (int i = 0; i < iN; ++i) cin >> arrHeight[i];
	sort(arrHeight.begin(), arrHeight.end(), greater<>());

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		++iAns;
		if (arrHeight[i] >= iB) break;
		iB -= arrHeight[i];
	}
	cout << iAns << "\n";
	return 0;
}
