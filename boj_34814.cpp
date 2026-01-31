#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecCount(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecCount[i];
	}

	while (iM-- > 0)
	{
		int iLikeNum, iDisLikeNum;
		cin >> iLikeNum >> iDisLikeNum;

		int iMax = 0;
		for (int i = 1; i <= iN; ++i)
		{
			iMax = max(iMax, vecCount[i]);
		}
		if (iMax == vecCount[iDisLikeNum]) continue;
		vecCount[iLikeNum]--;
	}

	for (int i = 1; i <= iN; ++i)
	{
		cout << vecCount[i] << (i == iN ? "\n" : " ");
	}
	return 0;
}
