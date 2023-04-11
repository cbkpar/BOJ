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

	string strCode;
	cin >> strCode;

	int iSize = strCode.length();

	int iCount = 0;
	for (int i = 0; i < iSize; ++i)
	{
		if (strCode[i] == 'M')
		{
			++iCount;
		}
		else
		{
			cout << "5";
			while (iCount >= 1)
			{
				--iCount;
				cout << "0";
			}
		}
	}
	while (iCount >= 1)
	{
		--iCount;
		cout << "1";
	}
	cout << "\n";

	for (int i = 0; i < iSize; ++i)
	{
		if (strCode[i] == 'M')
		{
			++iCount;
		}
		else
		{
			if (iCount > 0)
			{
				--iCount;
				cout << "1";
				while (iCount >= 1)
				{
					--iCount;
					cout << "0";
				}
			}
			cout << "5";
		}
	}
	if (iCount > 0)
	{
		--iCount;
		cout << "1";
		while (iCount >= 1)
		{
			--iCount;
			cout << "0";
		}
	}
	cout << "\n";
	return 0;
}
