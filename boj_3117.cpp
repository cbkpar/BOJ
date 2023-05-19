#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK, iM;
	cin >> iN >> iK >> iM;

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) cin >> vecNum[i];

	vector<int> vecRotate(iK + 1, 0);
	for (int i = 1; i <= iK; ++i) cin >> vecRotate[i];

	--iM;
	while (iM)
	{
		if (iM & 1)
		{
			vector<int> vecTemp(iN + 1, 0);
			for (int i = 1; i <= iN; ++i)
			{
				vecTemp[i] = vecRotate[vecNum[i]];
			}
			for (int i = 1; i <= iN; ++i)
			{
				vecNum[i] = vecTemp[i];
			}
		}
		vector<int> vecTemp(iK + 1, 0);
		for (int i = 1; i <= iK; ++i)
		{
			vecTemp[i] = vecRotate[vecRotate[i]];
		}
		for (int i = 1; i <= iK; ++i)
		{
			vecRotate[i] = vecTemp[i];
		}
		iM /= 2;
	}
	for (int i = 1; i <= iN; ++i)
	{
		cout << vecNum[i] << (i == iN ? "\n" : " ");
	}
	return 0;
}
