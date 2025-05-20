#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	map<string, string> mapWord;

	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;

		string strTemp = "";
		for (char ch : strWord)
		{
			if (ch >= 'A' && ch <= 'C') strTemp = strTemp + "2";
			if (ch >= 'D' && ch <= 'F') strTemp = strTemp + "3";
			if (ch >= 'G' && ch <= 'I') strTemp = strTemp + "4";
			if (ch >= 'J' && ch <= 'L') strTemp = strTemp + "5";
			if (ch >= 'M' && ch <= 'O') strTemp = strTemp + "6";
			if (ch >= 'P' && ch <= 'S') strTemp = strTemp + "7";
			if (ch >= 'T' && ch <= 'V') strTemp = strTemp + "8";
			if (ch >= 'W' && ch <= 'Z') strTemp = strTemp + "9";
		}

		if (mapWord.find(strTemp) == mapWord.end())
		{
			mapWord[strTemp] = strWord;
		}
	}

	int iM;
	cin >> iM;
	bool bFirst = true;


	string strTemp = "";
	for (int i = 0;i < iM;++i)
	{
		int iNum;
		cin >> iNum;

		if (iNum == 1)
		{
			if (!bFirst)
			{
				cout << " ";
			}
			bFirst = false;
			if (mapWord.find(strTemp) != mapWord.end())
			{
				cout << mapWord[strTemp];
			}
			else
			{
				for (int j = 0;j < strTemp.size();++j)
				{
					cout << "*";
				}
			}
			strTemp = "";
		}
		else
		{
			strTemp = strTemp + (char)(iNum + '0');
		}
	}

	if (!bFirst)
	{
		cout << " ";
	}
	if (mapWord.find(strTemp) != mapWord.end())
	{
		cout << mapWord[strTemp];
	}
	else
	{
		for (int j = 0;j < strTemp.size();++j)
		{
			cout << "*";
		}
	}
	cout << "\n";

	return 0;
}
