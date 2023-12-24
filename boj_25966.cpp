#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iQ;
	cin >> iN >> iM >> iQ;

	vector<vector<int>> vecNum(iN, vector<int>(iM, 0));
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cin >> vecNum[i][j];
		}
	}
	vector<int> vecRow(iN, 0);
	for (int i = 0; i < iN; ++i) vecRow[i] = i;

	while (iQ--)
	{
		int iCommand;
		cin >> iCommand;
		if (iCommand == 1)
		{
			int iA, iB;
			cin >> iA >> iB;
			swap(vecNum[vecRow[iA]], vecNum[vecRow[iB]]);
		}
		else
		{
			int iA, iB, iC;
			cin >> iA >> iB >> iC;
			vecNum[vecRow[iA]][iB] = iC;
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cout << vecNum[vecRow[i]][j] << (j == iM - 1 ? "\n" : " ");
		}
	}

	return 0;
}
