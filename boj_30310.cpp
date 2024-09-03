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

	vector<int> vecCount(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecCount[i];
	}

	sort(vecCount.begin(), vecCount.end());
	int iAns = vecCount[0] + vecCount[1];

	cout << iAns << "\n";
	return 0;
}
