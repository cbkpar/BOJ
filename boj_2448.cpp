#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void Divide(vector<string>& vecString, int iR, int iC, int iK)
{
	if (iK == 3)
	{
		vecString[iR][iC] = '*';
		vecString[iR + 1][iC - 1] = '*';
		vecString[iR + 1][iC + 1] = '*';
		for (int i = -2; i <= 2; ++i)
		{
			vecString[iR + 2][iC + i] = '*';
		}
		return;
	}
	Divide(vecString, iR, iC, iK / 2);
	Divide(vecString, iR + iK / 2, iC - iK / 2, iK / 2);
	Divide(vecString, iR + iK / 2, iC + iK / 2, iK / 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iDegree = 3;
	int iLevel = 1;
	int iLength = 5;

	while (iDegree < iN)
	{
		iDegree *= 2;
		iLength = iLength * 2 + 1;
		iLevel += 1;
	}
	vector<string> vecAns(iN);
	for (int i = 0; i < iN; ++i)
	{
		vecAns[i].resize(iLength);
		for (int j = 0; j < iLength; ++j)
		{
			vecAns[i][j] = ' ';
		}
	}
	Divide(vecAns, 0, iLength / 2, iN);
	for (int i = 0; i < iN; ++i)
	{
		cout << vecAns[i] << "\n";
	}
	return 0;
}
