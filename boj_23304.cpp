#include <iostream>
#include <string>

using namespace std;

bool IsAka(string& strWord, int iLeft, int iRight)
{
	for (int i = iLeft; i <= iRight; ++i)
	{
		if (strWord[i] != strWord[iRight + iLeft - i])
		{
			return false;
		}
	}
	if (iLeft < iRight)
	{
		int iMid = (iLeft + iRight) / 2;
		if ((iRight - iLeft) % 2 == 0)
		{
			return IsAka(strWord, iLeft, iMid - 1) && IsAka(strWord, iMid + 1, iRight);
		}
		else
		{
			return IsAka(strWord, iLeft, iMid) && IsAka(strWord, iMid + 1, iRight);
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string strWord;
	cin >> strWord;
	int iLen = strWord.length();
	cout << (IsAka(strWord, 0, iLen - 1) ? "AKARAKA" : "IPSELENTI") << "\n";
	return 0;
}
