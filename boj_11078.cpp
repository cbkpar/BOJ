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

	string strPIN, strPattern;
	cin >> strPIN >> strPattern;

	int iAns = 0;
	int iNow = 0;
	int iLen = strPIN.length();

	bool bPossible = true;
	for (char ch : strPattern)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			int iCount = ch - 'a' + 1;
			if (iNow + iCount > iLen)
			{
				bPossible = false;
				break;
			}
			for (int i = 0;i < iCount;++i)
			{
				iAns += strPIN[iNow++] - '0';
			}
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			int iCount = ch - 'A' + 1;
			if (iNow + iCount > iLen)
			{
				bPossible = false;
				break;
			}
			iNow += iCount;
		}
	}

	if (iNow != iLen)
	{
		bPossible = false;
	}

	if (bPossible)
	{
		cout << iAns << "\n";
	}
	else
	{
		cout << "non sequitur" << "\n";
	}
	
	return 0;
}
