#include <iostream>
#include <string>

using namespace std;

int iNumberCount[10] = { 0, };

int main()
{
	string str;
	cin >> str;
	int iLen = str.length();
	if (iLen == 1)
	{
		cout << "0\n";
		return 0;
	}
	int iCount = iLen - 1;
	while (iCount > 0)
	{
		++iNumberCount[str[iCount] - '0'];
		if (str[iCount] - str[iCount - 1] <= 0)
		{
			if (--iCount == 0)
			{
				cout << "0\n";
				return 0;
			}
		}
		else
		{
			++iNumberCount[str[iCount - 1] - '0'];
			--iCount;
			break;
		}
	}
	for (int i = 0; i < iCount; ++i)
	{
		cout << str[i];
	}
	for (int i = (str[iCount] - '0' + 1); i <= 9; ++i)
	{
		if (iNumberCount[i] > 0)
		{
			--iNumberCount[i];
			cout << i;
			break;
		}
	}
	for (int i = 0; i <= 9; ++i)
	{
		while (iNumberCount[i]--)
		{
			cout << i;
		}
	}
	cout << "\n";
	return 0;
}
