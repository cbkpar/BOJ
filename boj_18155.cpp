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

	int iN, iM;
	cin >> iN >> iM;

	vector<string> vecBad(iN, "");
	for (int i = 0;i < iN;++i)
	{
		cin >> vecBad[i];
		int iLen = vecBad[i].length();
		for (int j = 0;j < iLen;++j)
		{
			if (vecBad[i][j] == '0') vecBad[i][j] = 'O';
			if (vecBad[i][j] == '1') vecBad[i][j] = 'L';
			if (vecBad[i][j] == '2') vecBad[i][j] = 'Z';
			if (vecBad[i][j] == '3') vecBad[i][j] = 'E';
			if (vecBad[i][j] == '5') vecBad[i][j] = 'S';
			if (vecBad[i][j] == '6') vecBad[i][j] = 'B';
			if (vecBad[i][j] == '7') vecBad[i][j] = 'T';
			if (vecBad[i][j] == '8') vecBad[i][j] = 'B';
		}
	}
	for (int i = 0;i < iM;++i)
	{
		string strWord;
		cin >> strWord;
		int iLen = strWord.length();
		for (int j = 0;j < iLen;++j)
		{
			if (strWord[j] == '0') strWord[j] = 'O';
			if (strWord[j] == '1') strWord[j] = 'L';
			if (strWord[j] == '2') strWord[j] = 'Z';
			if (strWord[j] == '3') strWord[j] = 'E';
			if (strWord[j] == '5') strWord[j] = 'S';
			if (strWord[j] == '6') strWord[j] = 'B';
			if (strWord[j] == '7') strWord[j] = 'T';
			if (strWord[j] == '8') strWord[j] = 'B';
		}
		bool bPossible = true;
		for (int j = 0;j < iN;++j)
		{
			if (strWord.find(vecBad[j]) != string::npos)
			{
				bPossible = false;
			}
		}
		cout << (bPossible ? "VALID" : "INVALID") << "\n";
	}
	return 0;
}
