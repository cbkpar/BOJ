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

	string strA = "qwertasdfgzxcvb";
	string strB = "yuiophjklnm";

	string strWord;
	cin >> strWord;

	bool bPossible1 = true;
	int iLen = strWord.length();
	for (int i = 0;i < iLen;++i)
	{
		if (i % 2 == 0)
		{
			bool bFound = false;
			for (char ch : strA)
			{
				if (ch == strWord[i])
				{
					bFound = true;
				}
			}
			if (!bFound) bPossible1 = false;
		}
		else
		{
			bool bFound = false;
			for (char ch : strB)
			{
				if (ch == strWord[i])
				{
					bFound = true;
				}
			}
			if (!bFound) bPossible1 = false;
		}
	}


	bool bPossible2 = true;
	for (int i = 0;i < iLen;++i)
	{
		if (i % 2 == 1)
		{
			bool bFound = false;
			for (char ch : strA)
			{
				if (ch == strWord[i])
				{
					bFound = true;
				}
			}
			if (!bFound) bPossible2 = false;
		}
		else
		{
			bool bFound = false;
			for (char ch : strB)
			{
				if (ch == strWord[i])
				{
					bFound = true;
				}
			}
			if (!bFound) bPossible2 = false;
		}
	}

	if (bPossible1 || bPossible2)
	{
		cout << "yes" << "\n";
	}
	else
	{
		cout << "no" << "\n";
	}
	return 0;
}
