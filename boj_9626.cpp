#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iM, iN;
	cin >> iM >> iN;

	int iU, iL, iR, iD;
	cin >> iU >> iL >> iR >> iD;

	int iMaxR = iM + iU + iD;
	int iMaxC = iN + iL + iR;
	vector<string> vecAns(iMaxR);
	for (int i = 0; i < iMaxR; ++i) vecAns[i].resize(iMaxC);
	for (int i = 0; i < iMaxR; ++i)
	{
		for (int j = 0; j < iMaxC; ++j)
		{
			vecAns[i][j] = (i + j) % 2 == 0 ? '#' : '.';
		}
	}
	for (int i = 0; i < iM; ++i)
	{
		string strTemp;
		cin >> strTemp;
		for (int j = 0; j < iN; ++j)
		{
			vecAns[iU + i][iL + j] = strTemp[j];
		}
	}
	for (string strWord : vecAns)
	{
		cout << strWord << "\n";
	}

	return 0;
}
