#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

string arrString[20] = { "", };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iR, iC;
	cin >> iR >> iC;
	for (int i = 0; i < iR; ++i)
	{
		cin >> arrString[i];
	}
	list<string> listAns;
	for (int i = 0; i < iR; ++i)
	{
		string strTemp = "";
		for (int j = 0; j < iC; ++j)
		{
			if (arrString[i][j] == '#')
			{
				if (strTemp.length() >= 2)
				{
					listAns.emplace_back(strTemp);
				}
				strTemp = "";

			}
			else
			{
				strTemp += arrString[i][j];
			}
		}
		if (strTemp.length() >= 2)
		{
			listAns.emplace_back(strTemp);
		}
	}	
	for (int j = 0; j < iC; ++j)
	{
		string strTemp = "";
		for (int i = 0; i < iR; ++i)
		{
			if (arrString[i][j] == '#')
			{
				if (strTemp.length() >= 2)
				{
					listAns.emplace_back(strTemp);
				}
				strTemp = "";

			}
			else
			{
				strTemp += arrString[i][j];
			}
		}
		if (strTemp.length() >= 2)
		{
			listAns.emplace_back(strTemp);
		}
	}
	listAns.sort();
	cout << listAns.front() << "\n";

	return 0;
}
