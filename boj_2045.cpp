#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> matNum(3, vector<int>(3, 0));
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> matNum[i][j];
		}
	}

	if (matNum[0][0] == 0 && matNum[1][1] == 0 && matNum[2][2] == 0)
	{
		int iAPlusC = matNum[1][0] + matNum[1][2];
		int iAMinusC = matNum[2][0] + matNum[2][1] - matNum[0][1] - matNum[0][2];
		int iA = (iAPlusC + iAMinusC) / 2;
		matNum[0][0] = iA;
	}
	else if (matNum[0][2] == 0 && matNum[1][1] == 0 && matNum[2][0] == 0)
	{
		int iAPlusC = matNum[1][0] + matNum[1][2];
		int iAMinusC = matNum[2][1] + matNum[2][2] - matNum[0][0] - matNum[0][1];
		int iA = (iAPlusC + iAMinusC) / 2;
		matNum[0][2] = iA;
	}

	int iSum = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (matNum[i][0] != 0 && matNum[i][1] != 0 && matNum[i][2] != 0)
		{
			iSum = matNum[i][0] + matNum[i][1] + matNum[i][2];
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		if (matNum[0][i] != 0 && matNum[1][i] != 0 && matNum[2][i] != 0)
		{
			iSum = matNum[0][i] + matNum[1][i] + matNum[2][i];
		}
	}
	if (matNum[0][0] != 0 && matNum[1][1] != 0 && matNum[2][2] != 0)
	{
		iSum = matNum[0][0] + matNum[1][1] + matNum[2][2];
	}
	if (matNum[0][2] != 0 && matNum[1][1] != 0 && matNum[2][0] != 0)
	{
		iSum = matNum[0][2] + matNum[1][1] + matNum[2][0];
	}

	for (int t = 0; t < 3; ++t)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (matNum[i][0] == 0 && matNum[i][1] != 0 && matNum[i][2] != 0)
			{
				matNum[i][0] = iSum - matNum[i][1] - matNum[i][2];
			}
			if (matNum[i][0] != 0 && matNum[i][1] == 0 && matNum[i][2] != 0)
			{
				matNum[i][1] = iSum - matNum[i][0] - matNum[i][2];
			}
			if (matNum[i][0] != 0 && matNum[i][1] != 0 && matNum[i][2] == 0)
			{
				matNum[i][2] = iSum - matNum[i][0] - matNum[i][1];
			}
			if (matNum[0][i] == 0 && matNum[1][i] != 0 && matNum[2][i] != 0)
			{
				matNum[0][i] = iSum - matNum[1][i] - matNum[2][i];
			}
			if (matNum[0][i] != 0 && matNum[1][i] == 0 && matNum[2][i] != 0)
			{
				matNum[1][i] = iSum - matNum[0][i] - matNum[2][i];
			}
			if (matNum[0][i] != 0 && matNum[1][i] != 0 && matNum[2][i] == 0)
			{
				matNum[2][i] = iSum - matNum[0][i] - matNum[1][i];
			}
		}

		if (matNum[0][0] == 0 && matNum[1][1] != 0 && matNum[2][2] != 0)
		{
			matNum[0][0] = iSum - matNum[1][1] - matNum[2][2];
		}
		if (matNum[0][0] != 0 && matNum[1][1] == 0 && matNum[2][2] != 0)
		{
			matNum[1][1] = iSum - matNum[0][0] - matNum[2][2];
		}
		if (matNum[0][0] != 0 && matNum[1][1] != 0 && matNum[2][2] == 0)
		{
			matNum[2][2] = iSum - matNum[0][0] - matNum[1][1];
		}

		if (matNum[0][2] == 0 && matNum[1][1] != 0 && matNum[2][0] != 0)
		{
			matNum[0][2] = iSum - matNum[1][1] - matNum[2][0];
		}
		if (matNum[0][2] != 0 && matNum[1][1] == 0 && matNum[2][0] != 0)
		{
			matNum[1][1] = iSum - matNum[0][2] - matNum[2][0];
		}
		if (matNum[0][2] != 0 && matNum[1][1] != 0 && matNum[2][0] == 0)
		{
			matNum[2][0] = iSum - matNum[0][2] - matNum[1][1];
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << matNum[i][j] << (j == 2 ? "\n" : " ");
		}
	}
	return 0;
}
