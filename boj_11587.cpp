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

	int iN;
	cin >> iN;
	vector<string> vecWord(iN, "");
	for (int i = 0;i < iN;++i)
	{
		cin >> vecWord[i];
	}
	
	string strWord;
	cin >> strWord;

	int iAns = 0;
	int iLen = strWord.length();
	for (int i = 0;i < iN;++i)
	{
		if (vecWord[i].length() != strWord.length())
		{
			continue;
		}

		string strTemp = "";
		for (int j = 0;j < iLen;++j)
		{
			if (vecWord[i][j] >= 'a' && vecWord[i][j] <= 'c') strTemp += "2";
			if (vecWord[i][j] >= 'd' && vecWord[i][j] <= 'f') strTemp += "3";
			if (vecWord[i][j] >= 'g' && vecWord[i][j] <= 'i') strTemp += "4";
			if (vecWord[i][j] >= 'j' && vecWord[i][j] <= 'l') strTemp += "5";
			if (vecWord[i][j] >= 'm' && vecWord[i][j] <= 'o') strTemp += "6";
			if (vecWord[i][j] >= 'p' && vecWord[i][j] <= 's') strTemp += "7";
			if (vecWord[i][j] >= 't' && vecWord[i][j] <= 'v') strTemp += "8";
			if (vecWord[i][j] >= 'w' && vecWord[i][j] <= 'z') strTemp += "9";
		}
		if (strTemp == strWord)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
