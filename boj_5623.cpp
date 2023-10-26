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

	if (iN == 2)
	{
		cout << "1 1" << "\n";
		return 0;
	}

	vector<vector<int>> matNum(iN, vector<int>(iN, 0));
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> matNum[i][j];
		}
	}

	int iA = (matNum[0][1] + matNum[0][2] - matNum[1][2]) / 2;

	cout << iA << " ";
	for (int i = 1; i < iN; ++i)
	{
		cout << (matNum[0][i] - iA) << ((i == iN - 1) ? "\n" : " ");
	}
	return 0;
}
