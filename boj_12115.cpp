#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	vector<vector<int>> vecNum(iN, vector<int>(iM, 0));
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cin >> vecNum[i][j];
		}
	}

	int iQ;
	cin >> iQ;
	vector<int> vecTemp(iM, 0);
	while (iQ--)
	{
		int iAns = 0;
		for (int i = 0; i < iM; ++i)
		{
			cin >> vecTemp[i];
		}
		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iM; ++j)
			{
				if (vecTemp[j] != -1 && vecTemp[j] != vecNum[i][j]) break;
				if (j == iM - 1) ++iAns;
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
