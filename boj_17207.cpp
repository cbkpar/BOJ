#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> matA(5, vector<int>(5, 0));
	vector<vector<int>> matB(5, vector<int>(5, 0));

	for (int i = 0;i < 5;++i)
	{
		for (int j = 0;j < 5;++j)
		{
			cin >> matA[i][j];
		}
	}
	for (int i = 0;i < 5;++i)
	{
		for (int j = 0;j < 5;++j)
		{
			cin >> matB[i][j];
		}
	}

	vector<int> vecSum(5, 0);
	for (int i = 0;i < 5;++i)
	{
		for (int j = 0;j < 5;++j)
		{
			for (int k = 0;k < 5;++k)
			{
				vecSum[i] += matA[i][k] * matB[k][j];
			}
		}
	}


	int vecAns = -1;
	int vecMax = 2147483647;

	for (int i = 0;i < 5;++i)
	{
		if (vecSum[i] <= vecMax)
		{
			vecMax = vecSum[i];
			vecAns = i;
		}
	}

	if (vecAns == 0) cout << "Inseo" << "\n";
	if (vecAns == 1) cout << "Junsuk" << "\n";
	if (vecAns == 2) cout << "Jungwoo" << "\n";
	if (vecAns == 3) cout << "Jinwoo" << "\n";
	if (vecAns == 4) cout << "Youngki" << "\n";

	return 0;
}
