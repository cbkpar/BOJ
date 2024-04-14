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

	string strWord;
	cin >> strWord;

	int iLen = strWord.length();
	int iLeft = 0;
	int iRight = 0;

	for (int i = 0;i < iLen;++i)
	{
		if (strWord[i] == 'U')
		{
			iLeft = i;
			break;
		}
	}

	for (int i = iLen-1;i >= 0;--i)
	{
		if (strWord[i] == 'F')
		{
			iRight = i;
			break;
		}
	}

	for (int i = 0;i < iLeft;++i)
	{
		strWord[i] = '-';
	}
	strWord[iLeft] = 'U';
	for (int i = iLeft+1;i < iRight;++i)
	{
		strWord[i] = 'C';
	}
	strWord[iRight] = 'F';
	for (int i = iRight+1;i < iLen;++i)
	{
		strWord[i] = '-';
	}

	cout << strWord << "\n";
	return 0;
}
