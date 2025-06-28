#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iX, iC, iK;
	cin >> iX >> iC >> iK;
	vector<int> vecNum(iX + 1, 0);
	vector<bool> vecUsed(iC + 1, false);

	vector<tuple<int, int, int>> vecLog;
	for (int i = 0;i < iK;++i)
	{
		int iT, iS, iN;
		cin >> iT >> iS >> iN;
		vecLog.push_back(make_tuple(iT, iS, iN));
	}
	sort(vecLog.begin(), vecLog.end());

	for (int i = 0;i < iK;++i)
	{
		int iS = get<1>(vecLog[i]);
		int iN = get<2>(vecLog[i]);

		if (vecUsed[iS]) continue;
		if (vecNum[iN] != 0)
		{
			vecUsed[vecNum[iN]] = false;
		}
		vecNum[iN] = iS;
		vecUsed[iS] = true;
	}

	for (int i = 1;i <= iX;++i)
	{
		if (vecNum[i] != 0)
		{
			cout << i << " " << vecNum[i] << "\n";
		}
	}
	return 0;
}
