#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<map<string, map<string, string>>> mapWord(9, map<string, map<string, string>>());

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strWord;
		cin >> strWord;

		int iLen = strWord.length();
		string strKey1 = "aa";
		strKey1[0] = strWord[0];
		strKey1[1] = strWord[iLen - 1];

		string strKey2 = "00000000000000000000000000";
		for (int i = 0; i < iLen; ++i)
		{
			int iOrder = strWord[i] - 'a';
			++strKey2[iOrder];
		}
		mapWord[iLen][strKey1][strKey2] = strWord;
	}

	int iM;
	cin >> iM;
	for (int i = 0; i < iM; ++i)
	{
		string strWord;
		cin >> strWord;

		int iLen = strWord.length();
		string strKey1 = "aa";
		strKey1[0] = strWord[0];
		strKey1[1] = strWord[iLen - 1];

		string strKey2 = "00000000000000000000000000";
		for (int i = 0; i < iLen; ++i)
		{
			int iOrder = strWord[i] - 'a';
			++strKey2[iOrder];
		}

		cout << mapWord[iLen][strKey1][strKey2];
		cout << (i == iM - 1 ? "\n" : " ");
	}
	return 0;
}
