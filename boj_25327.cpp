#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int matCount[4][4][4] = { 0, };
string arrSub[4] = { "kor", "eng", "math", "-" };
string arrFruit[4] = { "apple", "pear", "orange", "-" };
string arrColor[4] = { "red", "blue", "green", "-" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	while (iN--)
	{
		string strSub, strFruit, strColor;
		cin >> strSub >> strFruit >> strColor;

		int iSub, iFruit, iColor;
		for (int i = 0; i < 3; ++i) if (strSub == arrSub[i]) iSub = i;
		for (int i = 0; i < 3; ++i) if (strFruit == arrFruit[i]) iFruit = i;
		for (int i = 0; i < 3; ++i) if (strColor == arrColor[i]) iColor = i;
		for (int i = 0; i < 8; ++i)
		{
			int iTempSub = ((i & (1 << 0)) == (1 << 0)) ? 3 : iSub;
			int iTempFruit = ((i & (1 << 1)) == (1 << 1)) ? 3 : iFruit;
			int iTempColor = ((i & (1 << 2)) == (1 << 2)) ? 3 : iColor;
			++matCount[iTempSub][iTempFruit][iTempColor];
		}
	}
	while (iM--)
	{
		string strSub, strFruit, strColor;
		cin >> strSub >> strFruit >> strColor;

		int iSub, iFruit, iColor;
		for (int i = 0; i < 4; ++i) if (strSub == arrSub[i]) iSub = i;
		for (int i = 0; i < 4; ++i) if (strFruit == arrFruit[i]) iFruit = i;
		for (int i = 0; i < 4; ++i) if (strColor == arrColor[i]) iColor = i;

		cout << matCount[iSub][iFruit][iColor] << "\n";
	}
	return 0;
}
