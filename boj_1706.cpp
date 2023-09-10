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

	int iN, iM;
	cin >> iN >> iM;

	vector<string> vecWord(iN, "");
	for (int i = 0; i < iN; ++i) cin >> vecWord[i];

	vector<string> vecAns;
	for (int i = 0; i < iN; ++i)
	{
		string strTemp = "";
		for (int j = 0; j < iM; ++j)
		{
			if (vecWord[i][j] == '#')
			{
				if (strTemp.length() >= 2)
				{
					vecAns.push_back(strTemp);
				}
				strTemp = "";
			}
			else
			{
				strTemp = strTemp + vecWord[i][j];
			}
		}
		if (strTemp.length() >= 2)
		{
			vecAns.push_back(strTemp);
		}
	}

	for (int i = 0; i < iM; ++i)
	{
		string strTemp = "";
		for (int j = 0; j < iN; ++j)
		{
			if (vecWord[j][i] == '#')
			{
				if (strTemp.length() >= 2)
				{
					vecAns.push_back(strTemp);
				}
				strTemp = "";
			}
			else
			{
				strTemp = strTemp + vecWord[j][i];
			}
		}
		if (strTemp.length() >= 2)
		{
			vecAns.push_back(strTemp);
		}
	}
	sort(vecAns.begin(), vecAns.end());
	cout << vecAns[0] << "\n";
	return 0;
}
