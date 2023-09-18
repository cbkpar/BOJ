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

	long long lAns = 0;
	vector<vector<long long>> dpFirst(iN, vector<long long>(3, 0));
	dpFirst[0][0] = 0;
	dpFirst[0][1] = 1;
	dpFirst[0][2] = 0;
	for (int i = 1; i < iN - 1; ++i)
	{
		dpFirst[i][0] = max(max(dpFirst[i - 1][0], dpFirst[i - 1][1]), dpFirst[i - 1][2]);
		dpFirst[i][1] = max(dpFirst[i - 1][0], dpFirst[i - 1][2]) + 1;
		dpFirst[i][2] = max(max(dpFirst[i - 1][0], dpFirst[i - 1][1]), dpFirst[i - 1][2]) + vecNum[i];
	}
	dpFirst[iN - 1][0] = max(max(dpFirst[iN - 2][0], dpFirst[iN - 2][1]), dpFirst[iN - 2][2]);
	dpFirst[iN - 1][2] = max(max(dpFirst[iN - 2][0], dpFirst[iN - 2][1]), dpFirst[iN - 2][2]) + vecNum[iN - 1];

	vector<vector<long long>> dpSecond(iN, vector<long long>(3, 0));
	dpSecond[0][0] = 0;
	dpSecond[0][1] = 0;
	dpSecond[0][2] = vecNum[0];
	for (int i = 1; i < iN; ++i)
	{
		dpSecond[i][0] = max(max(dpSecond[i - 1][0], dpSecond[i - 1][1]), dpSecond[i - 1][2]);
		dpSecond[i][1] = max(dpSecond[i - 1][0], dpSecond[i - 1][2]) + 1;
		dpSecond[i][2] = max(max(dpSecond[i - 1][0], dpSecond[i - 1][1]), dpSecond[i - 1][2]) + vecNum[i];
	}

	lAns = max(lAns, dpFirst[iN - 1][0]);
	lAns = max(lAns, dpFirst[iN - 1][1]);
	lAns = max(lAns, dpFirst[iN - 1][2]);
	lAns = max(lAns, dpSecond[iN - 1][0]);
	lAns = max(lAns, dpSecond[iN - 1][1]);
	lAns = max(lAns, dpSecond[iN - 1][2]);

	cout << lAns << "\n";
	return 0;
}
