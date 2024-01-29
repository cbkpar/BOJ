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

	bool bPossible = true;
	string strWord;
	cin >> strWord;

	int iLen = strWord.length();
	vector<int> vecNum(iLen, 0);
	for (int i = 0;i < iLen;++i)
	{
		if (strWord[i] == 'a') vecNum[i] = 1;
		if (strWord[i] == 'e') vecNum[i] = 1;
		if (strWord[i] == 'i') vecNum[i] = 1;
		if (strWord[i] == 'o') vecNum[i] = 1;
		if (strWord[i] == 'u') vecNum[i] = 1;
	}
	for (int i = 1;i < iLen;++i)
	{
		if (vecNum[i] == vecNum[i - 1]) bPossible = false;
	}

	cout << (bPossible ? "1" : "0") << "\n";
	return 0;
}
