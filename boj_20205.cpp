#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<vector<int>> vecNum(iN, vector<int>(iN, 0));
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> vecNum[i][j];
		}
	}
	for (int i = 0; i < iN * iK; ++i)
	{
		for (int j = 0; j < iN * iK; ++j)
		{
			cout << vecNum[i / iK][j / iK] << (j + 1 == iN * iK ? "\n" : " ");
		}
	}
	return 0;
}
