#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> vecS(14, false);
	vector<bool> vecB(14, false);
	vector<bool> vecV(14, false);
	vector<bool> vecK(14, false);

	for (int i = 0; i < 51; ++i)
	{
		string strCode;
		int iNum;
		cin >> strCode >> iNum;
		if (strCode == "S") vecS[iNum] = true;
		if (strCode == "B") vecB[iNum] = true;
		if (strCode == "V") vecV[iNum] = true;
		if (strCode == "K") vecK[iNum] = true;
	}
	for (int i = 1; i <= 13; ++i)
	{
		if (!vecS[i])
		{
			cout << "S " << i << "\n";
		}
		if (!vecB[i])
		{
			cout << "B " << i << "\n";
		}
		if (!vecV[i])
		{
			cout << "V " << i << "\n";
		}
		if (!vecK[i])
		{
			cout << "K " << i << "\n";
		}
	}
	return 0;
}
