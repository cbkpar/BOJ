#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CheckIncrease(const vector<vector<int>>& matNum)
{
	int iSize = matNum.size();
	for (int i = 1; i < iSize; ++i)
	{
		if (matNum[0][i] < matNum[0][i - 1]) return false;
		if (matNum[i][0] < matNum[i - 1][0]) return false;
	}
	return true;
}

void Rotate(vector<vector<int>>& matNum)
{
	int iSize = matNum.size();
	vector<vector<int>> matTemp(iSize, vector<int>(iSize, 0));
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			matTemp[i][j] = matNum[i][j];
		}
	}
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			matNum[i][j] = matTemp[j][iSize - 1 - i];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<vector<int>> matNum(iN, vector<int>(iN, 0));
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> matNum[i][j];
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (CheckIncrease(matNum)) break;
		Rotate(matNum);
	}
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cout << matNum[i][j] << (j == iN - 1 ? "\n" : " ");
		}
	}
	return 0;
}
