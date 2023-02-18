#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> arrNumber(26);

int RomToInt(string str)
{
	int iSize = str.length();
	int iTemp = arrNumber[str[iSize - 1] - 'A'];

	for (int i = iSize - 2; i >= 0; --i)
	{
		if (arrNumber[str[i] - 'A'] < arrNumber[str[i + 1] - 'A'])
		{
			iTemp -= arrNumber[str[i] - 'A'];
		}
		else
		{
			iTemp += arrNumber[str[i] - 'A'];
		}
	}
	return iTemp;
}

string intToRom(int iNum)
{
	string strTemp = "";
	while (iNum >= 1000)
	{
		iNum -= 1000;
		strTemp += "M";
	}
	int iD = iNum / 500;
	iNum %= 500;
	int iC = iNum / 100;
	iNum %= 100;
	int iL = iNum / 50;
	iNum %= 50;
	int iX = iNum / 10;
	iNum %= 10;
	int iV = iNum / 5;
	iNum %= 5;
	int iI = iNum;

	if (iC == 4)
	{
		strTemp += (iD == 1 ? "CM" : "CD");
	}
	else
	{
		if (iD == 1) strTemp += "D";
		while (iC--) strTemp += "C";
	}

	if (iX == 4)
	{
		strTemp += (iL == 1 ? "XC" : "XL");
	}
	else
	{
		if (iL == 1) strTemp += "L";
		while (iX--) strTemp += "X";
	}

	if (iI == 4)
	{
		strTemp += (iV == 1 ? "IX" : "IV");
	}
	else
	{
		if (iV == 1) strTemp += "V";
		while (iI--) strTemp += "I";
	}
	
	return strTemp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arrNumber['I' - 'A'] = 1;
	arrNumber['V' - 'A'] = 5;
	arrNumber['X' - 'A'] = 10;
	arrNumber['L' - 'A'] = 50;
	arrNumber['C' - 'A'] = 100;
	arrNumber['D' - 'A'] = 500;
	arrNumber['M' - 'A'] = 1000;

	string strA, strB;
	cin >> strA >> strB;

	int iSum = RomToInt(strA) + RomToInt(strB);

	cout << iSum << "\n" << intToRom(iSum) << "\n";
	return 0;
}
