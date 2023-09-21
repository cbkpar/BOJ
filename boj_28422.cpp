#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CalcCount(int iNum)
{
	int iRet = 0;
	while (iNum)
	{
		if (iNum & 1)
		{
			++iRet;
		}
		iNum >>= 1;
	}
	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) cin >> vecNum[i];

	vector<int> vecScore(iN + 1, 0);
	for (int i = 2; i <= iN; ++i)
	{
		if (i != 3) vecScore[i] = max(vecScore[i], vecScore[i - 2] + CalcCount(vecNum[i - 1] ^ vecNum[i]));
		if (i >= 3 && i != 4)
		{
			vecScore[i] = max(vecScore[i], vecScore[i - 3] + CalcCount(vecNum[i - 2] ^ vecNum[i - 1] ^ vecNum[i]));
		}
	}

	cout << vecScore[iN] << "\n";
	return 0;
}
