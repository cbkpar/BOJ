#include <iostream>
#include <string>

using namespace std;

int arrCount[26] = { 0, };

int main()
{
	string str;
	cin >> str;
	int iSize = str.length();
	for (int i = 0; i < iSize; ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			++arrCount[int(str[i] - 'a')];
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			++arrCount[int(str[i] - 'A')];
		}
	}
	int iMax = 0;
	int iIndex = -1;
	for (int i = 0; i < 26; ++i)
	{
		if (arrCount[i] > iMax)
		{
			iMax = arrCount[i];
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		if (arrCount[i] == iMax)
		{
			if (iIndex != -1)
			{
				cout << "?" << endl;
				return 0;
			}
			else
			{
				iIndex = i;
			}
		}
	}
	cout << char(iIndex + 'A') << endl;
	return 0;
}
