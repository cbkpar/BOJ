#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> matSigma(int iN, vector<vector<int>> matA, long long lB)
{
	if (lB == 1) return matA;
	vector<vector<int>> matRet = matSigma(iN, matA, lB / 2);
	vector<vector<int>> matRet2(iN, vector<int>(iN, 0));
	for (int i = 0; i < iN; ++i) matRet2[i][i] = 1;
	vector<vector<int>> matPow = matA;
	long long lTemp = lB / 2;
	while (lTemp)
	{
		if (lTemp & 1)
		{
			vector<vector<int>> matTemp(iN, vector<int>(iN, 0));
			for (int i = 0; i < iN; ++i) for (int j = 0; j < iN; ++j) for (int k = 0; k < iN; ++k) matTemp[i][j] += matRet2[i][k] * matPow[k][j];
			for (int i = 0; i < iN; ++i) for (int j = 0; j < iN; ++j) matRet2[i][j] = (matTemp[i][j]) % 1000;
		}
		vector<vector<int>> matTemp(iN, vector<int>(iN, 0));
		for (int i = 0; i < iN; ++i) for (int j = 0; j < iN; ++j) for (int k = 0; k < iN; ++k) matTemp[i][j] += matPow[i][k] * matPow[k][j];
		for (int i = 0; i < iN; ++i) for (int j = 0; j < iN; ++j) matPow[i][j] = (matTemp[i][j]) % 1000;
		lTemp /= 2;
	}
	for (int i = 0; i < iN; ++i) matRet2[i][i] += 1;
	vector<vector<int>> matTemp(iN, vector<int>(iN, 0));
	for (int i = 0; i < iN; ++i) for (int j = 0; j < iN; ++j) for (int k = 0; k < iN; ++k) matTemp[i][j] += matRet[i][k] * matRet2[k][j];
	for (int i = 0; i < iN; ++i) for (int j = 0; j < iN; ++j) matRet[i][j] = (matTemp[i][j]) % 1000;

	if (lB % 2 == 1)
	{
		vector<vector<int>> matRet3(iN, vector<int>(iN, 0));
		for (int i = 0; i < iN; ++i) matRet3[i][i] = 1;
		vector<vector<int>> matPow = matA;
		long long lTemp = lB;
		while (lTemp)
		{
			if (lTemp & 1)
			{
				vector<vector<int>> matTemp(iN, vector<int>(iN, 0));
				for (int i = 0; i < iN; ++i) for (int j = 0; j < iN; ++j) for (int k = 0; k < iN; ++k) matTemp[i][j] += matRet3[i][k] * matPow[k][j];
				for (int i = 0; i < iN; ++i) for (int j = 0; j < iN; ++j) matRet3[i][j] = (matTemp[i][j]) % 1000;
			}
			vector<vector<int>> matTemp(iN, vector<int>(iN, 0));
			for (int i = 0; i < iN; ++i) for (int j = 0; j < iN; ++j) for (int k = 0; k < iN; ++k) matTemp[i][j] += matPow[i][k] * matPow[k][j];
			for (int i = 0; i < iN; ++i) for (int j = 0; j < iN; ++j) matPow[i][j] = (matTemp[i][j]) % 1000;
			lTemp /= 2;
		}
		for (int i = 0; i < iN; ++i) for (int j = 0; j < iN; ++j) matRet[i][j] = (matRet[i][j] + matRet3[i][j]) % 1000;
	}
	return matRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	long long lB;
	cin >> iN >> lB;
	vector<vector<int>> matNum(iN, vector<int>(iN, 0));
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> matNum[i][j];
			matNum[i][j] %= 1000;
		}
	}

	vector<vector<int>> matAns = matSigma(iN, matNum, lB);
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cout << matAns[i][j] << (j == iN - 1 ? "\n" : " ");
		}
	}
	return 0;
}
