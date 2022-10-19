#include <iostream>
#include <string>

using namespace std;

int iMP, iMF, iMS, iMV;
int iN;
int matInfo[16][5] = { 0, };

int iMaxCost = 2147483647;
int iAnsCount = 0;
int arrAns[16] = { 0, };
int arrTemp[16] = { 0, };

void dfs(int iIndex, int iCount, int iP, int iF, int iS, int iV, int iCost)
{
	if (iP >= iMP && iF >= iMF && iS >= iMS && iV >= iMV && iMaxCost > iCost)
	{
		iMaxCost = iCost;
		for (int i = 0; i < iN; ++i)
		{
			arrAns[i] = arrTemp[i];
			iAnsCount = iCount;
		}
		return;
	}
	for (int i = iIndex; i < iN; ++i)
	{
		arrTemp[iCount] = i;
		dfs(i + 1, iCount + 1, iP + matInfo[i][0], iF + matInfo[i][1], iS + matInfo[i][2], iV + matInfo[i][3], iCost + matInfo[i][4]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN;
	cin >> iMP >> iMF >> iMS >> iMV;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> matInfo[i][j];
		}
	}
	dfs(0, 0, 0, 0, 0, 0, 0);
	if (iMaxCost == 2147483647)
	{
		cout << "-1";
	}
	else
	{
		cout << iMaxCost << "\n";
		cout << (arrAns[0] + 1);
		for (int i = 1; i < iAnsCount; ++i)
		{
			cout << " " << (arrAns[i] + 1);
		}
		cout << "\n";
	}
	return 0;
}
