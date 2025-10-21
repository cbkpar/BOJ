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

	vector<vector<int>> matNum(iN + 1, vector<int>());
	for (int i = 0;i < iN * 2;++i)
	{
		int iNum;
		cin >> iNum;
		matNum[iNum].push_back(i);
	}

	int iAns = 0;
	for (int i = 1;i <= iN;++i)
	{
		iAns = max(iAns, matNum[i][1] - matNum[i][0] - 1);
	}

	cout << iAns << "\n";
	return 0;
}
